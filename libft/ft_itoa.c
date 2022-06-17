/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:17:09 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 17:15:50 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_arr(int *num, int n)
{
	int	idx;

	idx = 0;
	if (n == 0)
		num[idx++] = 0;
	else
	{
		while (n)
		{
			num[idx++] = n % 10;
			n /= 10;
		}
	}
	return (idx);
}

static void	make_string(char *input, int idx, int size, int *num)
{
	int	sign;

	sign = 1;
	if (size - idx == 1)
	{
		input[0] = '-';
		sign = -1;
	}
	while (--idx != -1)
		input[size - idx - 1] = num[idx] * sign + '0';
	input[size] = '\0';
}

char	*ft_itoa(int n)
{
	int		num[10];
	int		idx;
	int		size;
	char	*output;

	idx = fill_arr(num, n);
	size = idx;
	if (n < 0)
		size++;
	output = (char *)malloc(sizeof(char) * size + 1);
	if (!output)
		return (0);
	make_string(output, idx, size, num);
	return (output);
}

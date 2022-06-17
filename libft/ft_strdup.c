/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:01:51 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 15:50:27 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*output;
	int		size;
	int		idx;

	size = 0;
	idx = 0;
	while (s1[size])
		size++;
	output = (char *)malloc(sizeof(char) * (size + 1));
	if (!output)
		return (0);
	while (size--)
		output[idx++] = *s1++;
	output[idx] = '\0';
	return (output);
}

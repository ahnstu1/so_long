/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:59:30 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 21:07:16 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	sign;
	long long	output;

	sign = 1;
	output = 0;
	while (*str == ' ' || *str == '\v' || *str == '\f' || *str == '\r'
		|| *str == '\n' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == -1 && output > 0 && output * 10 <= 0)
			return (0);
		else if (output > 0 && output * 10 <= 0)
			return (-1);
		output *= 10;
		output += *(str++) - '0';
	}
	return (output * sign);
}

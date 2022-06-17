/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:20:08 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 17:23:51 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(int n, int fd)
{
	char	output;

	if (n < 0)
		output = n % 10 * -1 + '0';
	else
		output = n % 10 + '0';
	if (n != 0)
	{
		print(n / 10, fd);
		write(fd, &output, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	else
		print(n, fd);
}

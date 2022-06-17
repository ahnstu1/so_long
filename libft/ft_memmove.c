/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:05:31 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 15:50:22 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c;
	const char	*t;

	c = dst;
	t = src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		while (len--)
			*(c++) = *(t++);
	else
	{
		c += len;
		t += len;
		while (len--)
			*(--c) = *(--t);
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:19:29 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 21:08:29 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s;
	const char	*c;

	s = s1;
	c = s2;
	while (n--)
	{
		if (*(unsigned char *)s != *(unsigned char *)c)
			return (*(unsigned char *)s - *(unsigned char *)c);
		s++;
		c++;
	}
	return (0);
}

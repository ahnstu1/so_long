/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:11:50 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 17:34:13 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && n--)
	{
		s1++;
		s2++;
		if (!*s1 && !*s2)
			return (0);
	}
	if (n == 0 && s1--)
		s2--;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

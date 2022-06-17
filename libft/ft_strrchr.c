/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:40:46 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 19:05:31 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	if (c >= 256)
		c %= 256;
	idx = 0;
	while (s[idx])
		idx++;
	while (idx != -1 && s[idx] != c)
		idx--;
	if (idx == -1)
		return (0);
	return ((char *)(s + idx));
}

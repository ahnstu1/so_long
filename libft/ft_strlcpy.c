/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:08:28 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 21:09:25 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	idx;
	size_t	src_size;

	idx = 0;
	src_size = ft_strlen(src);
	if (!dstsize)
		return (src_size);
	while (idx < dstsize - 1 && idx < src_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (src_size);
}

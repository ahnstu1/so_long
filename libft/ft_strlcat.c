/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:12:04 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 15:50:30 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	idx;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	idx = 0;
	if (dstsize < dst_size + 1)
		return (src_size + dstsize);
	while (*dst)
		dst++;
	while (dstsize > dst_size + idx + 1 && src[idx] != '\0')
		*dst++ = src[idx++];
	*dst = '\0';
	return (src_size + dst_size);
}

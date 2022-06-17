/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:23:29 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 19:08:36 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hidx;
	size_t	nidx;

	hidx = 0;
	if (!*haystack && !*needle)
		return ((char *)haystack);
	while (haystack[hidx])
	{
		nidx = 0;
		while (needle[nidx] && haystack[hidx + nidx] == needle[nidx])
			nidx++;
		if (hidx + nidx > len)
			return (0);
		if (needle[nidx] == '\0')
			return ((char *)(haystack + hidx));
		hidx++;
	}
	return (0);
}

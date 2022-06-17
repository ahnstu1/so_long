/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:14:44 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 20:05:17 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	int		idx;
	int		size;

	idx = 0;
	size = ft_strlen(s) - start;
	if (size < 0)
	{
		output = (char *)malloc(sizeof(char) * 1);
		output[0] = '\0';
		return (output);
	}
	if ((unsigned int)size < len)
		len = size;
	output = (char *)malloc(sizeof(char) * len + 1);
	if (!output)
		return (0);
	while (start-- && *s)
		s++;
	while (len-- && *s)
		output[idx++] = *(s++);
	output[idx] = '\0';
	return (output);
}

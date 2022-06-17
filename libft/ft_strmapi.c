/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:17:31 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 16:44:02 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		idx;
	char	*output;

	idx = 0;
	size = ft_strlen(s);
	output = (char *)malloc(sizeof(char) * size + 1);
	if (!output)
		return (0);
	while (idx < size)
	{
		output[idx] = f(idx, s[idx]);
		idx++;
	}
	output[idx] = '\0';
	return (output);
}

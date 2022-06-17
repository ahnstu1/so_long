/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:16:12 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 18:34:49 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pardon(char const s, char const *set)
{
	while (*set)
		if (*(set++) == s)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*output;
	const char	*start;
	int			idx;

	idx = 0;
	while (*s1 && pardon(*s1, set))
		s1++;
	start = s1;
	if (*s1)
	{
		while (*(s1 + 1))
			s1++;
		while (pardon(*s1, set))
			s1--;
		s1++;
		if (s1 - start < 0)
			start = s1;
	}
	output = (char *)malloc(sizeof(char) * (s1 - start + 1));
	if (!output)
		return (0);
	while (s1 - start)
		output[idx++] = *(start++);
	output[idx] = '\0';
	return (output);
}

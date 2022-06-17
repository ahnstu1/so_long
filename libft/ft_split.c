/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:16:47 by hahn              #+#    #+#             */
/*   Updated: 2021/12/08 21:08:45 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**all_free(char **input, int idx)
{
	while (idx == -1)
		free(input[idx--]);
	return (NULL);
}

static int	split_check(char const *s, char c)
{
	if (*s && *s != c && (!*(s + 1) || *(s + 1) == c))
		return (1);
	return (0);
}

static int	split_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s == c)
		s++;
	while (!split_check(s, c))
	{
		size++;
		s++;
	}
	return (size + 1);
}

static int	split_maker(char const *s, char *d, char c, int size)
{
	int	idx;
	int	add;

	idx = -1;
	add = 0;
	while (*s == c)
	{
		s++;
		add++;
	}
	while (++idx < size)
	{
		d[idx] = *(s++);
		add++;
	}
	d[idx] = '\0';
	return (add + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		size;
	int		idx;
	int		in_size;

	size = 0;
	idx = -1;
	while (s[++idx])
		if (split_check(s + idx, c))
			size++;
	output = (char **)malloc(sizeof(char *) * (size + 1));
	if (!output)
		return (NULL);
	idx = -1;
	while (++idx < size)
	{
		in_size = split_size(s, c);
		output[idx] = (char *)malloc(sizeof(char) * (in_size + 1));
		if (!output[idx])
			return (all_free(output, idx));
		s += split_maker(s, output[idx], c, in_size);
	}
	output[idx] = NULL;
	return (output);
}

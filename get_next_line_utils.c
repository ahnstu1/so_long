/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 05:31:04 by hahn              #+#    #+#             */
/*   Updated: 2022/06/20 02:59:56 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gnl_strlen(char *s1)
{
	int	idx;

	idx = 0;
	if (!s1)
		return (0);
	while (s1[idx])
		idx++;
	return (idx);
}

char	*gnl_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char) c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*output;
	int		len;
	int		idx;
	int		s2_idx;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	len = gnl_strlen(s1) + gnl_strlen(s2);
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	idx = -1;
	while (s1[++idx])
		output[idx] = s1[idx];
	s2_idx = 0;
	while (s2[s2_idx])
		output[idx++] = s2[s2_idx++];
	output[idx] = '\0';
	free(s1);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:04:41 by hahn              #+#    #+#             */
/*   Updated: 2021/12/10 18:50:37 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*output;
	size_t	idx;

	idx = 0;
	output = (char *)malloc(count * size);
	if (!output)
		return (0);
	while (idx < count * size)
		output[idx++] = '\0';
	return (output);
}

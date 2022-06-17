/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:30:32 by hahn              #+#    #+#             */
/*   Updated: 2021/12/13 05:15:35 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_list)
		return (NULL);
	new_list->content = (*f)(lst->content);
	new_list->next = NULL;
	output = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = (t_list *)malloc(sizeof(t_list) * 1);
		if (!new_list->next)
		{
			ft_lstclear(&output, del);
			return (NULL);
		}
		new_list = new_list->next;
		new_list->content = (*f)(lst->content);
		new_list->next = NULL;
		lst = lst->next;
	}
	new_list = NULL;
	return (output);
}

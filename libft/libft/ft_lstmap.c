/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:26:41 by skunert           #+#    #+#             */
/*   Updated: 2023/04/01 16:48:22 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_node;

	first_node = NULL;
	if (lst != NULL && f != NULL)
	{
		new_lst = ft_lstnew(f(lst->content));
		first_node = new_lst;
		lst = lst->next;
		while (lst != NULL)
		{
			new_lst->next = ft_lstnew(f(lst->content));
			if (new_lst == NULL)
			{
				ft_lstclear(&new_lst, del);
				free(new_lst);
				return (NULL);
			}
			new_lst = new_lst->next;
			lst = lst->next;
		}
		new_lst = NULL;
	}
	return (first_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:03:07 by skunert           #+#    #+#             */
/*   Updated: 2023/03/23 08:30:30 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr_pos;

	i = 0;
	curr_pos = lst;
	while (curr_pos != NULL)
	{
		i++;
		curr_pos = curr_pos->next;
	}
	return (i);
}

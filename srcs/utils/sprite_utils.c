/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:24:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/24 16:33:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_lst_sprites(t_sprite *lst)
{
	t_sprite	*curr;
	t_sprite	*tmp;

	curr = lst;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

void	ft_get_location(t_game *game, char **map)
{
	int			i;
	int			j;
	t_sprite	*curr;

	i = 0;
	curr = game->sp;
	while (map[i] && curr)
	{
		j = 0;
		while (map[i][j] && curr)
		{
			if (map[i][j] == 'P')
			{
				curr->x = j * DIMENS + 20;
				curr->y = i * DIMENS + 20;
				curr = curr->next;
			}
			j++;
		}
		i++;
	}
}

void	sprite_init(t_sprite *start, t_map *m)
{
	int			i;
	t_sprite	*curr;
	t_sprite	*new_node;

	i = -1;
	curr = start;
	curr->state = 1;
	curr->type = 2;
	curr->x = 0;
	curr->y = 0;
	curr->z = 550;
	curr->next = NULL;
	while (++i < m->game->n_of_coll)
	{
		new_node = malloc(sizeof(t_sprite));
		new_node->state = 1;
		new_node->type = 2;
		new_node->x = 0;
		new_node->y = 0;
		new_node->z = 550;
		curr->next = new_node;
		curr = curr->next;
	}
	curr->next = NULL;
}

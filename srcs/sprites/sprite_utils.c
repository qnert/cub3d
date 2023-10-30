/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:24:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:26 by skunert          ###   ########.fr       */
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

void	ft_get_location(t_game *game, char **map, char c)
{
	int			i;
	int			j;
	t_sprite	*curr;

	i = 0;
	curr = game->sp;
	while (curr && curr->type != ft_atoi(&c))
		curr = curr->next;
	while (map[i] && curr)
	{
		j = 0;
		while (map[i][j] && curr)
		{
			if (map[i][j] == c && curr->x == 0 && curr->y == 0)
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

t_sprite	*new_lst_node_sprite(t_sprite *curr, t_sprite *new_node, int type)
{
	new_node = malloc(sizeof(t_sprite));
	new_node->state = 1;
	new_node->type = type;
	new_node->x = 0;
	new_node->y = 0;
	new_node->z = 550;
	curr->next = new_node;
	curr = curr->next;
	return (curr);
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
	new_node = NULL;
	while (++i < m->game->n_of_coll)
		curr = new_lst_node_sprite(curr, new_node, 2);
	i = -1;
	while (++i < m->game->n_of_water)
		curr = new_lst_node_sprite(curr, new_node, 3);
	curr = new_lst_node_sprite(curr, new_node, 4);
	curr->next = NULL;
}

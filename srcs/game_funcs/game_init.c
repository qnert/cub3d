/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:22:45 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 20:02:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_longest_line(char **matrix)
{
	unsigned int	check;
	unsigned int	i;

	check = ft_strlen(matrix[0]);
	i = 0;
	while (matrix[i])
	{
		if (check < ft_strlen(matrix[i]))
			check = ft_strlen(matrix[i]);
		i++;
	}
	return (check);
}

void	ft_game_begin(t_game *game, t_map *m)
{
	game->mlx = mlx_init(game->dis_w, game->dis_h, "One Piece it in!", true);
	get_images(game, m);
	m->error = ft_fill_map(game, m);
	if (m->error > 0)
		return (mlx_terminate(game->mlx));
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(game->mlx, ft_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	game_init(t_map *map)
{
	map->game->dis_w = 1440;
	map->game->dis_h = 900;
	map->game->width = get_longest_line(map->map);
	map->game->height = ft_matrixlen(map->map);
	ft_game_begin(map->game, map);
}

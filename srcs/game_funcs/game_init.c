/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:22:45 by skunert           #+#    #+#             */
/*   Updated: 2023/10/31 11:49:06 by skunert          ###   ########.fr       */
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

int	ft_game_begin(t_game *game, t_map *m)
{
	game->mlx = mlx_init(game->dis_w, game->dis_h, "One Piece it in!", true);
	get_images(game);
	if (ft_fill_map(game, m) == 1)
		return (mlx_terminate(game->mlx), 3);
	game->pl_x = game->player->instances[0].x;
	game->pl_y = game->player->instances[0].y;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(game->mlx, ft_hooks, game);
	mlx_loop(game->mlx);
	return (mlx_terminate(game->mlx), 0);
}

int	game_init(t_map *map)
{
	map->game->dis_w = 1440;
	map->game->dis_h = 900;
	map->game->width = get_longest_line(map->map);
	map->game->height = ft_matrixlen(map->map);
	if (ft_game_begin(map->game, map) == 1)
		return (1);
	return (0);
}

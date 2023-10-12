/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:22:45 by skunert           #+#    #+#             */
/*   Updated: 2023/10/12 09:27:37 by skunert          ###   ########.fr       */
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

int	ft_game_begin(t_game *game, char **map)
{
	game->mlx = mlx_init(game->dis_w, game->dis_h, "Raycast", true);
	get_images(game);
	ft_fill_map(game, map);
	game->pl_x = game->player->instances[0].x;
	game->pl_y = game->player->instances[0].y;
	mlx_loop_hook(game->mlx, ft_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

void	game_init(t_map *map)
{
	map->game->dis_w = 1024;
	map->game->dis_h = 640;
	map->game->width = get_longest_line(map->map);
	map->game->height = ft_matrixlen(map->map);
	ft_game_begin(map->game, map->map);
	return ;
}

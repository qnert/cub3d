/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:22:45 by skunert           #+#    #+#             */
/*   Updated: 2023/10/06 19:15:12 by njantsch         ###   ########.fr       */
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
	game->mlx = mlx_init(game->width * DIMENS, game->height * DIMENS, "Raycast", true);
	get_images(game);
	ft_fill_map(game, map);
	mlx_loop_hook(game->mlx, ft_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

void	game_init(t_map *map)
{
	map->game->width = get_longest_line(map->map);
	map->game->height = ft_matrixlen(map->map);
	ft_game_begin(map->game, map->map);
	return ;
}

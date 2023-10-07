/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/07 13:30:40 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_wall_and_space(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * 50, i * 50);
			else if (map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->space, j * 50, i * 50);
			else if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
				mlx_image_to_window(game->mlx, game->player,
					j * 50 + 20, i * 50 + 20);
			j++;
		}
		i++;
	}
}

void	ft_fill_map(t_game *game, char **map)
{
	ft_fill_wall_and_space(game, map);
	mlx_image_to_window(game->mlx, game->player, 0, 0);
}

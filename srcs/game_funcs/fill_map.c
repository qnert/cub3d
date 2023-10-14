/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/15 00:35:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				mlx_image_to_window(game->mlx, game->player,
					j * DIMENS + 20, i * DIMENS + 20);
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_map(t_game *game, char **map)
{
	ft_fill_player(game, map);
	game->wall_tex = mlx_load_png("./textures/window.png");
	game->floor_tex = mlx_load_png("./textures/metal.png");
	game->ceiling_tex = mlx_load_png("./textures/night_sky2.png");
	game->door_tex = mlx_load_png("./textures/door.png");
}

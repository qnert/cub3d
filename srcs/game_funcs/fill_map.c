/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
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
				mlx_image_to_window(game->mlx, game->wall, j * DIMENS, i * DIMENS);
			else if (map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->space, j * DIMENS, i * DIMENS);
			else if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
				mlx_image_to_window(game->mlx, game->player,
					j * DIMENS + 20, i * DIMENS + 20);
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

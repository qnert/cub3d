/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/16 13:12:47 by skunert          ###   ########.fr       */
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

int	ft_fill_map(t_game *game, t_map *m)
{
	ft_fill_player(game, m->map);
	game->wall_north_tex = mlx_load_png(m->texture_path_no);
	if (game->wall_north_tex == NULL)
		return (ft_error_msg("NO texture couldn't be opnened\n"), 1);
	game->wall_south_tex = mlx_load_png(m->texture_path_so);
	if (game->wall_south_tex == NULL)
		return (free(game->wall_north_tex),
			ft_error_msg("SO texture couldn't be opnened\n"), 1);
	game->wall_west_tex = mlx_load_png(m->texture_path_we);
	if (game->wall_west_tex == NULL)
		return (free(game->wall_north_tex), free(game->wall_south_tex),
			ft_error_msg("WE texture couldn't be opnened\n"), 1);
	game->wall_east_tex = mlx_load_png(m->texture_path_ea);
	if (game->wall_east_tex == NULL)
	{
		free(game->wall_north_tex);
		free(game->wall_south_tex);
		free(game->wall_west_tex);
		return (ft_error_msg("EA texture couldn't be opnened\n"),
			1);
	}
	game->floor_tex = mlx_load_png("./textures/metal.png");
	game->ceiling_tex = mlx_load_png("./textures/night_sky2.png");
	game->door_tex = mlx_load_png("./textures/door.png");
	return (0);
}

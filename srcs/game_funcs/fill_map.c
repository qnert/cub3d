/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 13:59:46 by skunert          ###   ########.fr       */
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

void	ft_clear_up_tex(t_game *g, int i)
{
	if (i == 1)
		free(g->wall_north_tex);
	if (i == 2)
	{
		free(g->wall_north_tex);
		free(g->wall_south_tex);
	}
	if (i == 3)
	{
		free(g->wall_north_tex);
		free(g->wall_south_tex);
		free(g->wall_east_tex);
	}
}

void	ft_get_location(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->sp->x = j * DIMENS + 20;
				game->sp->y = i * DIMENS + 20;
			}
			j++;
		}
		i++;
	}
}

int	ft_fill_map(t_game *game, t_map *m)
{
	ft_fill_player(game, m->map);
	ft_get_location(game, m->map);
	game->wall_north_tex = mlx_load_png(m->texture_path_no);
	if (game->wall_north_tex == NULL)
		return (ft_error_msg("NO texture couldn't be opnened\n"), 1);
	game->wall_south_tex = mlx_load_png(m->texture_path_so);
	if (game->wall_south_tex == NULL)
		return (ft_clear_up_tex(game, 1),
			ft_error_msg("SO texture couldn't be opnened\n"), 1);
	game->wall_west_tex = mlx_load_png(m->texture_path_we);
	if (game->wall_west_tex == NULL)
		return (ft_clear_up_tex(game, 2),
			ft_error_msg("WE texture couldn't be opnened\n"), 1);
	game->wall_east_tex = mlx_load_png(m->texture_path_ea);
	if (game->wall_east_tex == NULL)
		return (ft_clear_up_tex(game, 3),
			ft_error_msg("EA texture couldn't be opnened\n"), 1);
	game->floor_tex = mlx_load_png("./textures/metal.png");
	game->ceiling_tex = mlx_load_png("./textures/night_sky2.png");
	game->door_tex = mlx_load_png("./textures/door.png");
  game->sp->sp_tex = mlx_load_png("./textures/beer.png");
	return (0);
}

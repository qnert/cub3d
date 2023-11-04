/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/11/04 14:23:31 by njantsch         ###   ########.fr       */
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
				game->pl_x = j * DIMENS + 20;
				game->pl_y = i * DIMENS + 20;
			}
			j++;
		}
		i++;
	}
}

void	change_wall_tex_size(t_game *game, int tex)
{
	if (tex == 1 && game->tex->wall_north_tex->width > 64)
		game->tex->wall_north_tex->width = 64;
	if (tex == 1 && game->tex->wall_north_tex->height > 64)
		game->tex->wall_north_tex->height = 64;
	if (tex == 2 && game->tex->wall_south_tex->width > 64)
		game->tex->wall_south_tex->width = 64;
	if (tex == 2 && game->tex->wall_south_tex->height > 64)
		game->tex->wall_south_tex->height = 64;
	if (tex == 3 && game->tex->wall_west_tex->width > 64)
		game->tex->wall_west_tex->width = 64;
	if (tex == 3 && game->tex->wall_west_tex->height > 64)
		game->tex->wall_west_tex->height = 64;
	if (tex == 4 && game->tex->wall_east_tex->width > 64)
		game->tex->wall_east_tex->width = 64;
	if (tex == 4 && game->tex->wall_east_tex->height > 64)
		game->tex->wall_east_tex->height = 64;
}

bool	check_wall_tex_size(t_game *game)
{
	if (game->tex->wall_north_tex->width > 64
		|| game->tex->wall_north_tex->height > 64)
		return (change_wall_tex_size(game, 1), false);
	if (game->tex->wall_south_tex->width > 64
		|| game->tex->wall_south_tex->height > 64)
		return (change_wall_tex_size(game, 2), false);
	if (game->tex->wall_west_tex->width > 64
		|| game->tex->wall_west_tex->height > 64)
		return (change_wall_tex_size(game, 3), false);
	if (game->tex->wall_east_tex->width > 64
		|| game->tex->wall_east_tex->height > 64)
		return (change_wall_tex_size(game, 4), false);
	return (true);
}

int	ft_fill_map(t_game *game, t_map *m)
{
	ft_fill_player(game, m->map);
	game->tex->wall_north_tex = mlx_load_png(m->texture_path_no);
	if (game->tex->wall_north_tex == NULL)
		return (ft_error_msg("NO texture couldn't be opnened\n"), 3);
	game->tex->wall_south_tex = mlx_load_png(m->texture_path_so);
	if (game->tex->wall_south_tex == NULL)
		return (ft_clear_up_wall_tex(game, 1),
			ft_error_msg("SO texture couldn't be opnened\n"), 3);
	game->tex->wall_west_tex = mlx_load_png(m->texture_path_we);
	if (game->tex->wall_west_tex == NULL)
		return (ft_clear_up_wall_tex(game, 2),
			ft_error_msg("WE texture couldn't be opnened\n"), 3);
	game->tex->wall_east_tex = mlx_load_png(m->texture_path_ea);
	if (game->tex->wall_east_tex == NULL)
		return (ft_clear_up_wall_tex(game, 3),
			ft_error_msg("EA texture couldn't be opnened\n"), 3);
	if (check_wall_tex_size(game) == false)
		printf("Warning!\n\
wall texture bigger then 64x64 will result in undefined pixel behavior\n");
	if (ft_get_other_tex(game) == 3)
		return (3);
	return (0);
}

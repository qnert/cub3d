/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:07:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/04 15:08:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_chest_water_texture(t_game *game)
{
	game->tex->water_tex = mlx_load_png("./textures/water.png");
	if (game->tex->water_tex == NULL)
		return (ft_clear_up_other_tex(game, 4),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	game->tex->chest_tex = mlx_load_png("./textures/chest.png");
	if (game->tex->chest_tex == NULL)
		return (ft_clear_up_other_tex(game, 5),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	return (0);
}

int	ft_get_floor_sky_texture(t_game *game)
{
	if (FLOOR == 1)
	{
		game->tex->floor_tex
			= mlx_load_png("./textures/wooden_wall_no_window.png");
		if (game->tex->floor_tex == NULL)
			return (ft_error_msg("Wall texture couldn't be opened\n"),
				ft_clear_up_wall_tex(game, 4), 3);
	}
	if (SKY == 1)
	{
		game->tex->ceiling_tex = mlx_load_png("./textures/sky_with_clouds.png");
		if (game->tex->ceiling_tex == NULL)
			return (ft_clear_up_other_tex(game, 1),
				ft_error_msg("Ceiling texture couldn't be opened\n"),
				ft_clear_up_wall_tex(game, 4), 3);
	}
	return (0);
}

int	ft_get_other_tex(t_game *game)
{
	if (ft_get_floor_sky_texture(game) == 3)
		return (3);
	game->tex->door_tex = mlx_load_png("./textures/wood_door.png");
	if (game->tex->door_tex == NULL)
		return (ft_clear_up_other_tex(game, 2),
			ft_error_msg("Door texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	game->tex->coll_tex = mlx_load_png("./textures/beer.png");
	if (game->tex->coll_tex == NULL)
		return (ft_clear_up_other_tex(game, 3),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	if (ft_get_chest_water_texture(game) == 3)
		return (3);
	return (0);
}

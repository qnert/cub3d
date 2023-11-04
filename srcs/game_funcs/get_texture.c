/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/11/03 18:27:49 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

uint32_t	get_rgb_in_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	draw_sky_with_color(t_game *game, t_map *m)
{
	uint32_t	color;

	color = 0;
	if (SKY == 0)
	{
		game->ceiling = mlx_new_image(game->mlx,
				game->dis_w + 10, game->dis_h / 2 + 10);
		color = get_rgb_in_hex(m->ceiling_rgb[0],
				m->ceiling_rgb[1], m->ceiling_rgb[2]);
		set_pixels_img(game->ceiling, game->dis_w, game->dis_h / 2, color);
		mlx_image_to_window(game->mlx, game->ceiling, 0, 0);
		game->ceiling->instances[0].z = -1;
	}
}

void	draw_floor_with_color(t_game *game, t_map *m)
{
	uint32_t	color;

	color = 0;
	if (FLOOR == 0)
	{
		game->floor = mlx_new_image(game->mlx,
				game->dis_w + 10, game->dis_h / 2 + 10);
		color = get_rgb_in_hex(m->floor_rgb[0],
				m->floor_rgb[1], m->floor_rgb[2]);
		set_pixels_img(game->floor, game->dis_w, game->dis_h / 2, color);
		mlx_image_to_window(game->mlx, game->floor, 0, game->dis_h / 2);
		game->floor->instances[0].z = -2;
	}
}

void	get_images(t_game *game, t_map *m)
{
	game->ceiling = NULL;
	game->floor = NULL;
	draw_sky_with_color(game, m);
	draw_floor_with_color(game, m);
	game->background = mlx_new_image(game->mlx, game->dis_w, game->dis_h);
	set_pixels_img(game->background, game->dis_w, game->dis_h, 0x0000000F);
	game->minimap = mlx_new_image(game->mlx,
			game->width * DIMENS, game->height * DIMENS);
	game->line = mlx_new_image(game->mlx, game->dis_w + 20, game->dis_h + 20);
}

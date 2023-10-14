/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/14 02:23:49 by skunert          ###   ########.fr       */
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
			j++;
		}
		i++;
	}
}

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
				mlx_image_to_window(game->mlx, game->line,
					j * DIMENS + 24, i * DIMENS + 6);
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_map(t_game *game, char **map)
{
	// mlx_image_t	*cover;
	// mlx_image_t	*floor;
	mlx_image_t	*ceiling;

	// cover = mlx_new_image(game->mlx, game->width * DIMENS, game->height * DIMENS);
	ft_fill_wall_and_space(game, map);
	ft_fill_player(game, map);
	// set_pixels_img(cover, game->width * DIMENS, game->height * DIMENS, 0x000000FF);
	// mlx_image_to_window(game->mlx, cover, 0, 0);
	// floor = mlx_new_image(game->mlx, game->dis_w, game->dis_h / 2);
	// mlx_image_to_window(game->mlx, floor, 0, game->dis_h / 2);
	// set_pixels_img(floor, game->dis_w, game->dis_h / 2, 0xFFF0FF);
	ceiling = mlx_new_image(game->mlx, game->dis_w, game->dis_h / 2);
	mlx_image_to_window(game->mlx, ceiling, 0, 0);
	set_pixels_img(ceiling, game->dis_w, game->dis_h / 2, 0xFFFFFFFF);
	game->wall_tex = mlx_load_png("./textures/trump.png");
	game->floor_tex = mlx_load_png("./textures/mossy.png");
	game->ceiling_tex = mlx_load_png("./textures/clouds.png");
	game->wall = mlx_new_image(game->mlx, game->dis_w, game->dis_h);
	mlx_image_to_window(game->mlx, game->wall, 0, 0);
// 	for (int y = 0; y < 64 * 8; y++)
// 	{
// 		for (int x = 0; x < 64 * 8; x++)
// 		{
// 			int pixel = (y / 8 * 64 + x / 8) * game->wall_text->bytes_per_pixel;
// 			int color = (int)game->wall_text->pixels[pixel] << 24
// 			| (int)game->wall_text->pixels[pixel + 1] << 16
// 			| (int)game->wall_text->pixels[pixel + 2] << 8
// 			| (int)game->wall_text->pixels[pixel + 3];
// 			mlx_put_pixel(game->wall, x, y, color);
// 		}
// 	}
}

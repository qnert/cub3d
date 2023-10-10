/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/10/09 17:08:02 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_img(t_game *game)
{
	game->wall = mlx_new_image(game->mlx, 50, 50);
	set_pixels_img(game->wall, 50, 50, 0x0000FF);
	game->space = mlx_new_image(game->mlx, 50 ,50);
	set_pixels_img(game->space, 50, 50, 0x00FF00);
}

void	get_player_img(t_game *game)
{
	game->player = mlx_new_image(game->mlx, 10, 10);
	set_pixels_img(game->player, 10, 10, 0x0000FF);
}

void	get_line_img(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->line = mlx_new_image(game->mlx, 1, 20);
	while (x < 1)
	{
		y = 0;
		while (y < 20)
		{
			mlx_put_pixel(game->line, x, y, 0xFFF00FFF);
			y++;
		}
		x++;
	}
}

void	get_images(t_game *game)
{
	get_player_img(game);
	get_map_img(game);
	get_line_img(game);
}

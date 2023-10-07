/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/10/07 13:29:57 by skunert          ###   ########.fr       */
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

void	get_images(t_game *game)
{
	get_player_img(game);
	get_map_img(game);
}

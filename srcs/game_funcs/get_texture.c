/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 13:30:39 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_img(t_game *game)
{
	game->player = mlx_new_image(game->mlx, 10, 10);
	set_pixels_img(game->player, 10, 10, 0x000000);
}

void	get_images(t_game *game)
{
	get_player_img(game);
	game->minimap = mlx_new_image(game->mlx,
		game->width * DIMENS, game->height * DIMENS);
	game->line = mlx_new_image(game->mlx, game->dis_w + 20, game->dis_h + 20);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 13:36:38 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_images(t_game *game)
{
	game->background = mlx_new_image(game->mlx, 1440, 900);
	set_pixels_img(game->background, 1440, 900, 0x0000000F);
	game->minimap = mlx_new_image(game->mlx,
			game->width * DIMENS, game->height * DIMENS);
	game->line = mlx_new_image(game->mlx, game->dis_w + 20, game->dis_h + 20);
}

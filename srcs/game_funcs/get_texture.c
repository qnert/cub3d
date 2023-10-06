/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/10/06 14:18:10 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_img(t_game *game)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png("./textures/player.png");
	game->player = mlx_texture_to_image(game->mlx, txt);
	free(txt);
	mlx_image_to_window(game->mlx, game->player, 0, 0);
}

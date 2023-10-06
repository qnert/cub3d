/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:44 by skunert           #+#    #+#             */
/*   Updated: 2023/10/06 15:11:33 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_img(t_game *game)
{
	mlx_texture_t	*tmp_wall;

	tmp_wall = mlx_load_png("./textures/crack.png");
	game->wall = mlx_texture_to_image(game->mlx, tmp_wall);
	free(tmp_wall);
	game->space = NULL;
}

void	get_player_img(t_game *game)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png("./textures/player.png");
	game->player = mlx_texture_to_image(game->mlx, txt);
	free(txt);
}

void	get_images(t_game *game)
{
	get_player_img(game);
	get_map_img(game);
}

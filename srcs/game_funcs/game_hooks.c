/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/15 00:40:39 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sky(t_game *g)
{
	for (int y = 0; y < 40; y++) {
		for (int x = 0; x < 120; x++)
		{
			int x_off = rad_to_degree(g->caster->pa) * 2 + x;
			if (x_off < 0)
				x_off += 120;
			x_off = x_off % 120;
			int pixel = (y * 120 + x_off) * g->ceiling_tex->bytes_per_pixel;
			int color = (int)g->ceiling_tex->pixels[pixel] << 24
			| (int)g->ceiling_tex->pixels[pixel + 1] << 16
			| (int)g->ceiling_tex->pixels[pixel + 2] << 8
			| (int)g->ceiling_tex->pixels[pixel + 3];
			for (int j = 0; j < 12; j++) {
				for (int i = 0; i < 12; i++)
					mlx_put_pixel(g->line, i+x*12, j+y*12, color);
			}
		}
	}
}

void	ft_rotate_left(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.05;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
}

void	ft_rotate_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.05;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
	}
}

void	ft_wall_offset_set(t_game *g)
{
	g->caster->pd_x = cos(g->caster->pa) * 6;
	g->caster->pd_y = sin(g->caster->pa) * 6;
	if (g->caster->pd_x < 0)
		g->caster->x_off = -20;
	else
		g->caster->x_off = 20;
	if (g->caster->pd_y < 0)
		g->caster->y_off = -20;
	else
		g->caster->y_off = 20;
	g->caster->pd_x_strafe = cos(g->caster->pa + M_PI_2) * 6;
	g->caster->pd_y_strafe = sin(g->caster->pa + M_PI_2) * 6;
	if (g->caster->pd_x_strafe < 0)
		g->caster->x_off_strafe = -20;
	else
		g->caster->x_off_strafe = 20;
	if (g->caster->pd_y_strafe < 0)
		g->caster->y_off_strafe = -20;
	else
		g->caster->y_off_strafe = 20;
}

void	ft_move(t_game *game)
{
	ft_wall_offset_set(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	ft_move_up_down(game);
	ft_move_left_right(game);
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	ft_rotate_left(game);
	ft_rotate_right(game);
	ft_move(game);
	ft_check_door(game);
	raycaster(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/30 21:33:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_game_exit(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (game->game_over == 2 && mlx_is_key_down(game->mlx, MLX_KEY_R))
	{
		game->game_over = 3;
		mlx_close_window(game->mlx);
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

void	check_game_over(t_game *game)
{
	mlx_texture_t	*g_over;
	mlx_image_t		*g_over_img;

	if (game->backg_fade < 57
		&& (game->game_over == 1 || game->game_over == 2))
	{
		g_over_img = NULL;
		mlx_delete_image(game->mlx, g_over_img);
		if (game->game_over == 1)
			g_over = mlx_load_png("./textures/win.png");
		else
			g_over = mlx_load_png("./textures/lose_resized.png");
		g_over_img = mlx_texture_to_image(game->mlx, g_over);
		mlx_delete_texture(g_over);
		mlx_image_to_window(game->mlx, game->background, 0, 0);
		mlx_image_to_window(game->mlx, g_over_img, 100, 50);
		game->backg_fade++;
	}
}

void	ft_hooks(void *param)
{
	int		x;
	int		y;
	int		diff;
	t_game	*game;

	x = 0;
	y = 0;
	diff = 0;
	game = param;
	check_game_exit(game);
	check_game_over(game);
	if (game->game_over == 0)
	{
		mlx_get_mouse_pos(game->mlx, &x, &y);
		diff = game->dis_w / 2 - x;
		mlx_set_mouse_pos(game->mlx, game->dis_w / 2, game->dis_h / 2);
		ft_rotate_left(game, diff);
		ft_rotate_right(game, diff);
		ft_move(game);
		ft_check_door(game);
		raycaster(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/30 18:33:48 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	mlx_texture_t	*win;
	mlx_image_t		*win_img;
	mlx_image_t		*background;

	if (game->game_over == 1)
	{
		win_img = NULL;
		background = NULL;
		mlx_delete_image(game->mlx, win_img);
		mlx_delete_image(game->mlx, background);
		win = mlx_load_png("./textures/win.png");
		win_img = mlx_texture_to_image(game->mlx, win);
		background = mlx_new_image(game->mlx, 1440, 900);
		set_pixels_img(background, 1440, 900, 0x0000000F);
		mlx_delete_texture(win);
		mlx_image_to_window(game->mlx, background, 0, 0);
		mlx_image_to_window(game->mlx, win_img, 100, 50);
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
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
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

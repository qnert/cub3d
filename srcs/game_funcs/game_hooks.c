/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/16 16:37:37 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.05;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
	else if (diff > 0)
	{
		if ((diff) > 150)
			diff = 150;
		game->caster->pa -= 0.0006 * diff;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
}

void	ft_rotate_right(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.05;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
	}
	else if (diff < 0)
	{
		if ((-diff) > 150)
			diff = -150;
		game->caster->pa += 0.0006 * (-diff);
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
	int	x;
	int	y;
	int	diff;
	t_game	*game;

	x = 0;
	y = 0;
	diff = 0;
	game = param;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	diff = game->dis_w / 2 - x;
	mlx_set_mouse_pos(game->mlx, game->dis_w / 2, game->dis_h / 2);
	ft_rotate_left(game, diff);
	ft_rotate_right(game, diff);
	ft_move(game);
	ft_check_door(game);
	raycaster(game);
}

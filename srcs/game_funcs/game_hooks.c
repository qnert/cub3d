/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 21:32:30 by njantsch         ###   ########.fr       */
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
	mlx_get_mouse_pos(game->mlx, &x, &y);
	diff = game->dis_w / 2 - x;
	mlx_set_mouse_pos(game->mlx, game->dis_w / 2, game->dis_h / 2);
	ft_rotate_left(game, diff);
	ft_rotate_right(game, diff);
	ft_move(game);
	ft_check_door(game);
	raycaster(game);
}

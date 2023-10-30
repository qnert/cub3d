/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:28:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/30 18:33:44 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_forward_movement(t_game *g)
{
	if (ft_check_collision(g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + g->caster->x_off) / DIMENS]))
	{
		if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
			g->pl_x += cos(g->caster->pa) * 10;
		else
			g->pl_x += cos(g->caster->pa) * 6;
	}
	if (ft_check_collision(g->caster->map
			[(int)(g->pl_y + g->caster->y_off) / DIMENS]
		[(int)g->pl_x / DIMENS]))
	{
		if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT_SHIFT))
			g->pl_y += sin(g->caster->pa) * 10;
		else
			g->pl_y += sin(g->caster->pa) * 6;
	}
}

void	ft_move_up_down(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
	{
		ft_forward_movement(g);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		if (ft_check_collision(g->caster->map[(int)g->pl_y / DIMENS]
				[(int)(g->pl_x - g->caster->x_off) / DIMENS]))
			g->pl_x -= cos(g->caster->pa) * 6;
		if (ft_check_collision(g->caster->map
				[(int)(g->pl_y - g->caster->y_off) / DIMENS]
			[(int)g->pl_x / DIMENS]))
			g->pl_y -= sin(g->caster->pa) * 6;
	}
}

void	ft_move_left_right(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
	{
		if (ft_check_collision(g->caster->map[(int)g->pl_y / DIMENS]
				[(int)(g->pl_x + g->caster->x_off_strafe) / DIMENS]))
			g->pl_x += cos(g->caster->pa + M_PI_2) * 6;
		if (ft_check_collision(g->caster->map
				[(int)(g->pl_y + g->caster->y_off_strafe) / DIMENS]
			[(int)g->pl_x / DIMENS]))
			g->pl_y += sin(g->caster->pa + M_PI_2) * 6;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A))
	{
		if (ft_check_collision(g->caster->map[(int)g->pl_y / DIMENS]
				[(int)(g->pl_x - g->caster->x_off_strafe) / DIMENS]))
			g->pl_x -= cos(g->caster->pa + M_PI_2) * 6;
		if (ft_check_collision(g->caster->map[(int)(g->pl_y
					- g->caster->y_off_strafe) / DIMENS]
			[(int)g->pl_x / DIMENS]))
			g->pl_y -= sin(g->caster->pa + M_PI_2) * 6;
	}
}

void	ft_move(t_game *game)
{
	ft_wall_offset_set(game);
	ft_move_up_down(game);
	ft_move_left_right(game);
}

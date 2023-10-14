/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:46:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/14 20:05:40 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_check_collision(char c)
{
	if (c == '1' || c == 'D')
		return (false);
	return (true);
}

void	ft_move_up_down(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
	{
		if (ft_check_collision(g->caster->map[(int)g->pl_y / DIMENS]
				[(int)(g->pl_x + g->caster->x_off) / DIMENS]))
			g->pl_x += cos(g->caster->pa) * 6;
		if (ft_check_collision(g->caster->map
				[(int)(g->pl_y + g->caster->y_off) / DIMENS]
			[(int)g->pl_x / DIMENS]))
			g->pl_y += sin(g->caster->pa) * 6;
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

void	ft_close_doors(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_Q))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + (g->caster->x_off * 3)) / DIMENS] == 'X'
			&& g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x) / DIMENS] != 'X')
			g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + (g->caster->x_off * 3)) / DIMENS] = 'D';
		else if (g->caster->map
			[(int)(g->pl_y + (g->caster->y_off * 3)) / DIMENS]
			[(int)g->pl_x / DIMENS] == 'X'
			&& g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x) / DIMENS] != 'X')
			g->caster->map
			[(int)(g->pl_y + (g->caster->y_off * 3)) / DIMENS]
			[(int)g->pl_x / DIMENS] = 'D';
	}
}

void	ft_check_door(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_E))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + (g->caster->x_off * 3)) / DIMENS] == 'D')
			g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + (g->caster->x_off * 3)) / DIMENS] = 'X';
		if (g->caster->map
			[(int)(g->pl_y + (g->caster->y_off * 3)) / DIMENS]
			[(int)g->pl_x / DIMENS] == 'D')
			g->caster->map
			[(int)(g->pl_y + (g->caster->y_off * 3)) / DIMENS]
			[(int)g->pl_x / DIMENS] = 'X';
	}
	ft_close_doors(g);
}

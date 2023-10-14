/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:46:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/14 16:47:56 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_move_up_down(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + g->caster->x_off) / DIMENS] != '1')
			g->pl_x += cos(g->caster->pa) * 6;
		if (g->caster->map[(int)(g->pl_y + g->caster->y_off) / DIMENS]
			[(int)g->pl_x / DIMENS] != '1')
			g->pl_y += sin(g->caster->pa) * 6;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x - g->caster->x_off) / DIMENS] != '1')
			g->pl_x -= cos(g->caster->pa) * 6;
		if (g->caster->map[(int)(g->pl_y - g->caster->y_off) / DIMENS]
			[(int)g->pl_x / DIMENS] != '1')
			g->pl_y -= sin(g->caster->pa) * 6;
	}
}

void	ft_move_left_right(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x + g->caster->x_off_strafe) / DIMENS] != '1')
			g->pl_x += cos(g->caster->pa + M_PI_2) * 6;
		if (g->caster->map[(int)(g->pl_y + g->caster->y_off_strafe)
			/ DIMENS]
			[(int)g->pl_x / DIMENS] != '1')
			g->pl_y += sin(g->caster->pa + M_PI_2) * 6;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A))
	{
		if (g->caster->map[(int)g->pl_y / DIMENS]
			[(int)(g->pl_x - g->caster->x_off_strafe) / DIMENS] != '1')
			g->pl_x -= cos(g->caster->pa + M_PI_2) * 6;
		if (g->caster->map[(int)(g->pl_y - g->caster->y_off_strafe)
			/ DIMENS]
			[(int)g->pl_x / DIMENS] != '1')
			g->pl_y -= sin(g->caster->pa + M_PI_2) * 6;
	}
}

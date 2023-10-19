/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:28:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/18 21:31:46 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	ft_move(t_game *game)
{
	ft_wall_offset_set(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	ft_move_up_down(game);
	ft_move_left_right(game);
}

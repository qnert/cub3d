/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:46:02 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 21:29:21 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_check_collision(char c)
{
	if (c == '1' || c == 'D')
		return (false);
	return (true);
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

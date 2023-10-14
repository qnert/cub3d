/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:27:23 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/13 21:08:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_variables_vertical(t_game *g)
{
	g->ray->dist_v = 100000;
	g->ray->player_x = g->pl_x;
	g->ray->player_y = g->pl_y;
	g->ray->ver_x = g->ray->player_x;
	g->ray->ver_y = g->ray->player_y;
	g->ray->depoffield = 0;
	g->ray->n_tan = -tan(g->ray->ray_a);
}

void	check_vertical_wall(t_game *g)
{
	while (g->ray->depoffield < 50)
	{
		g->caster->map_x = (int)g->ray->ray_x / DIMENS;
		g->caster->map_y = (int)g->ray->ray_y / DIMENS;
		if (g->caster->map_x < g->width && g->caster->map_y < g->height
			&& g->caster->map_x >= 0 && g->caster->map_y >= 0
			&& g->caster->map[g->caster->map_y][g->caster->map_x] == '1')
		{
			g->ray->ver_x = g->ray->ray_x;
			g->ray->ver_y = g->ray->ray_y;
			g->ray->dist_v = ft_distance(g, g->ray->ver_x, g->ray->ver_y);
			g->ray->depoffield = 50;
		}
		else
		{
			g->ray->ray_x += g->ray->x_o;
			g->ray->ray_y += g->ray->y_o;
			g->ray->depoffield += 1;
		}
	}
}

// checks the vertical lines of our map grids and determines if a wall
// is hit or not
void	check_vertical_line(t_game *g)
{
	assign_variables_vertical(g);
	if (g->ray->ray_a > M_PI_2 && g->ray->ray_a < 3 * M_PI_2)
	{
		g->ray->ray_x = (((int)g->ray->player_x / DIMENS) * DIMENS) - 0.0001;
		g->ray->ray_y =
			(g->ray->player_x - g->ray->ray_x) * g->ray->n_tan + g->ray->player_y;
		g->ray->x_o = -DIMENS;
		g->ray->y_o = -g->ray->x_o * g->ray->n_tan;
	}
	if (g->ray->ray_a < M_PI_2 || g->ray->ray_a > 3 * M_PI_2)
	{
		g->ray->ray_x = (((int)g->ray->player_x / DIMENS) * DIMENS) + DIMENS;
		g->ray->ray_y =
			(g->ray->player_x - g->ray->ray_x) * g->ray->n_tan + g->ray->player_y;
		g->ray->x_o = DIMENS;
		g->ray->y_o = -g->ray->x_o * g->ray->n_tan;
	}
	if (g->ray->ray_a == 0 || g->ray->ray_a == M_PI)
	{
		g->ray->ray_x = g->ray->player_x;
		g->ray->ray_y = g->ray->player_y;
		g->ray->depoffield = 50;
	}
	check_vertical_wall(g);
}

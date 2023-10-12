/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/11 20:00:03 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_variables_horizontal(t_game *g)
{
	g->ray->dist_h = 100000;
	g->ray->player_x = g->pl_x;
	g->ray->player_y = g->pl_y;
	g->ray->hor_x = g->ray->player_x;
	g->ray->hor_y = g->ray->player_y;
	g->ray->depoffield = 0;
	g->ray->a_tan = -1 / tan(g->ray->ray_a);
}

void	check_horizontal_wall(t_game *g)
{
	while (g->ray->depoffield < 50)
	{
		g->caster->map_x = (int)g->ray->ray_x / 50;
		g->caster->map_y = (int)g->ray->ray_y / 50;
		if (g->caster->map_x < g->width && g->caster->map_y < g->height
			&& g->caster->map_x >= 0 && g->caster->map_y >= 0
			&& g->caster->map[g->caster->map_y][g->caster->map_x] == '1')
		{
			g->ray->hor_x = g->ray->ray_x;
			g->ray->hor_y = g->ray->ray_y;
			g->ray->dist_h = ft_distance(g, g->ray->hor_x, g->ray->hor_y);
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

// checks the horizontal lines of our map grids and determines if a wall
// is hit or not
void	check_horizontal_line(t_game *g)
{
	assign_variables_horizontal(g);
	if (g->ray->ray_a > M_PI)
	{
		g->ray->ray_y = (((int)g->ray->player_y / 50) * 50) - 0.0001;
		g->ray->ray_x =
			(g->ray->player_y - g->ray->ray_y) * g->ray->a_tan + g->ray->player_x;
		g->ray->y_o = -50;
		g->ray->x_o = -g->ray->y_o * g->ray->a_tan;
	}
	if (g->ray->ray_a < M_PI)
	{
		g->ray->ray_y = (((int)g->ray->player_y / 50) * 50) + 50;
		g->ray->ray_x =
			(g->ray->player_y - g->ray->ray_y) * g->ray->a_tan + g->ray->player_x;
		g->ray->y_o = 50;
		g->ray->x_o = -g->ray->y_o * g->ray->a_tan;
	}
	if (g->ray->ray_a == 0 || g->ray->ray_a == M_PI)
	{
		g->ray->ray_x = g->ray->player_x;
		g->ray->ray_y = g->ray->player_y;
		g->ray->depoffield = 50;
	}
	check_horizontal_wall(g);
}

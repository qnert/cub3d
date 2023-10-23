/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:46:47 by skunert           #+#    #+#             */
/*   Updated: 2023/10/23 11:56:33 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_right_distance(t_game *g)
{
	if (g->ray->dist_v < g->ray->dist_h)
	{
		g->ray->shade = 0.8;
		g->ray->ray_x = g->ray->ver_x;
		g->ray->ray_y = g->ray->ver_y;
		g->ray->final_d = g->ray->dist_v;
	}
	if (g->ray->dist_h < g->ray->dist_v)
	{
		g->ray->shade = 1.0;
		g->ray->ray_x = g->ray->hor_x;
		g->ray->ray_y = g->ray->hor_y;
		g->ray->final_d = g->ray->dist_h;
	}
}

int	rad_to_degree(double rad)
{
	int	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

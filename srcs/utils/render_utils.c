/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:32 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 15:09:40 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_values_floor_ceiling(t_game *g)
{
	int	i;

	i = g->caster->line_hight + g->caster->line_offset;
	while (i < g->dis_h)
	{
		g->dl->dy = i - (g->dis_h / 2.0);
		g->dl->fix_ra = g->caster->ca;
		if (g->dl->fix_ra < 0)
			g->dl->fix_ra += 2 * M_PI;
		if (g->dl->fix_ra > 2 * M_PI)
			g->dl->fix_ra -= 2 * M_PI;
		g->dl->fix_ra = cos(g->dl->fix_ra);
		g->dl->tx = g->pl_x / 2 + cos(g->ray->ray_a) * 158
			* 3 * g->tex->floor_tex->width / g->dl->dy / g->dl->fix_ra;
		g->dl->ty = g->pl_y / 2 + sin(g->ray->ray_a) * 158
			* 3 * g->tex->floor_tex->width / g->dl->dy / g->dl->fix_ra;
		ft_draw_floor_ceiling(g, i);
		i++;
	}
}

void	ft_set_values_for_rendering(t_game *g)
{
	g->dl->ty = g->ray->ty_off * g->ray->ty_step;
	g->dl->begin_x = g->ray->rays * (g->dis_w / g->ray->n_of_rays);
	if (g->ray->shade == 1)
	{
		g->dl->tx = (int)(g->ray->ray_x / 2.0) % 64;
		if (g->ray->ray_a < M_PI)
			g->dl->tx = 63 - g->dl->tx;
	}
	else
	{
		g->dl->tx = (int)(g->ray->ray_y / 2.0) % 64;
		if (g->ray->ray_a > M_PI_2 && g->ray->ray_a < (3 * M_PI_2))
			g->dl->tx = 63 - g->dl->tx;
	}
}

void	ft_set_values_and_render_funcs(t_game *g)
{
	set_cosine_and_values(g);
	ft_set_values_for_rendering(g);
	ft_draw_walls(g);
	if (FLOOR == 1)
		ft_set_values_floor_ceiling(g);
	g->ray->ray_a += DGREE / 8;
	set_limit(g);
}

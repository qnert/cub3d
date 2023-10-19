/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/18 21:21:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// deletes and replaces image for new line
void	replace_img(t_game *g)
{
	mlx_delete_image(g->mlx, g->minimap);
	mlx_delete_image(g->mlx, g->line);
	g->line = mlx_new_image(g->mlx, g->dis_w + 20, g->dis_h + 20);
	g->minimap = mlx_new_image(g->mlx, g->dis_w, g->dis_h);
	mlx_image_to_window(g->mlx, g->line, 0, 0);
	mlx_image_to_window(g->mlx, g->minimap, 20, 20);
	g->line->instances[0].z = 0;
	g->minimap->instances[0].z = 1;
}

// sets limits for rotation
void	set_limit(t_game *g)
{
	if (g->ray->ray_a < 0)
		g->ray->ray_a += 2 * M_PI;
	if (g->ray->ray_a > 2 * M_PI)
		g->ray->ray_a -= 2 * M_PI;
}

// pythagorean theorem to get the length of the vector
double	ft_distance(t_game *g, double bx, double by)
{
	double	ax;
	double	ay;

	ax = g->pl_x;
	ay = g->pl_y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	set_cosine_and_values(t_game *g)
{
	g->caster->ca = g->caster->pa - g->ray->ray_a;
	if (g->caster->ca < 0)
		g->caster->ca += 2 * M_PI;
	if (g->caster->ca > 2 * M_PI)
		g->caster->ca -= 2 * M_PI;
	g->ray->final_d *= cos(g->caster->ca);
	g->caster->line_hight = DIMENS * g->dis_h / g->ray->final_d;
	g->ray->ty_step = 64.0 / (double)g->caster->line_hight;
	g->ray->ty_off = 0;
	if (g->caster->line_hight > g->dis_h)
	{
		g->ray->ty_off = (g->caster->line_hight - g->dis_h) / 2.0;
		g->caster->line_hight = g->dis_h;
	}
	g->caster->line_offset = (g->dis_h / 2) - g->caster->line_hight / 2;
	g->ray->final_d *= cos(g->caster->ca);
}

void	raycaster(t_game *g)
{
	g->ray->rays = -1;
	g->ray->ray_a = g->caster->pa - DGREE * 30;
	set_limit(g);
	replace_img(g);
	ft_fill_minimap(g);
	draw_sky(g);
	while (++g->ray->rays < g->ray->n_of_rays)
	{
		check_horizontal_line(g);
		check_vertical_line(g);
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
		draw_minimap(g);
		ft_set_values_and_render_funcs(g);
	}
}

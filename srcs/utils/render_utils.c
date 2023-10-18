/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:32 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 13:57:18 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_sprites(t_game *g)
{
	double sx = g->sp->x - g->pl_x;
	double sy = g->sp->y - g->pl_y;
	double sz = g->sp->z;
	double cs = cos(g->caster->pa);
	double sn = sin(g->caster->pa);
	double a = sy * cs * 12 - sx * sn * 12;
	double b = sx * cs + sy * sn;
	sx = (a * 108.0 / b) + (g->dis_w / 2);
	sy = (sz * 108.0 / b) + (g->dis_h / 2);
	if (sx > 0 && sy > g->dis_h / 2 && sx < g->dis_w && sy < g->dis_h) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				mlx_put_pixel(g->line,  j + sx, i + sy, 0x000000FF);
			}
		}
	}
}

void	ft_draw_walls(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->caster->line_hight)
	{
		g->dl->pixel = ((int)g->dl->ty * g->wall_north_tex->width
				+ (int)g->dl->tx)
			* g->wall_north_tex->bytes_per_pixel;
		g->dl->color = get_right_wall_color(g);
		j = -1;
		while (++j < 4)
			mlx_put_pixel(g->line, j + g->dl->begin_x,
				i + g->caster->line_offset, g->dl->color);
		g->dl->ty += g->ray->ty_step;
	}
}

void	ft_draw_floor_ceiling(t_game *g, int i)
{
	int	j;

	g->dl->pixel = (((int)g->dl->ty & (g->floor_tex->width / 2 - 1))
			* g->floor_tex->width + ((int)g->dl->tx
				& (g->floor_tex->width / 2 - 1)))
		* g->floor_tex->bytes_per_pixel;
	g->dl->color = (int)(g->floor_tex->pixels[g->dl->pixel]) << 24
		| (int)(g->floor_tex->pixels[g->dl->pixel + 1]) << 16
		| (int)(g->floor_tex->pixels[g->dl->pixel + 2]) << 8
		| (int)(g->floor_tex->pixels[g->dl->pixel + 3]);
	j = -1;
	while (++j < 8)
		mlx_put_pixel(g->line, j + g->dl->begin_x, i, g->dl->color);
	// g->dl->pixel = (((int)g->dl->ty & (g->ceiling_tex->width / 2 - 1))
	// 		* g->ceiling_tex->width + ((int)g->dl->tx
	// 			& (g->ceiling_tex->width / 2 - 1)))
	// 	* g->floor_tex->bytes_per_pixel;
	// g->dl->color = (int)(g->ceiling_tex->pixels[g->dl->pixel]) << 24
	// 	| (int)(g->ceiling_tex->pixels[g->dl->pixel + 1]) << 16
	// 	| (int)(g->ceiling_tex->pixels[g->dl->pixel + 2]) << 8
	// 	| (int)(g->ceiling_tex->pixels[g->dl->pixel + 3]);
	// j = -1;
	// while (++j < 8)
	// 	mlx_put_pixel(g->line, j + g->dl->begin_x, g->dis_h - i, g->dl->color);
}

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
			* 3 * g->floor_tex->width / g->dl->dy / g->dl->fix_ra;
		g->dl->ty = g->pl_y / 2 + sin(g->ray->ray_a) * 158
			* 3 * g->floor_tex->width / g->dl->dy / g->dl->fix_ra;
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
	ft_set_values_floor_ceiling(g);
	ft_draw_sprites(g);
	g->ray->ray_a += DGREE / 8;
	set_limit(g);
}

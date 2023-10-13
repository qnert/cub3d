/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/13 20:52:45 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// deletes and replaces image for new line
void	replace_img(t_game *g)
{
	mlx_delete_image(g->mlx, g->line);
	g->line = mlx_new_image(g->mlx, g->dis_w + 20, g->dis_h + 20);
	mlx_image_to_window(g->mlx, g->line, 0, 0);
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
	if (g->caster->line_hight > g->dis_h) {
		g->ray->ty_off = (g->caster->line_hight - g->dis_h) / 2.0;
		g->caster->line_hight = g->dis_h;
	}
	g->caster->line_offset = (g->dis_h / 2) - g->caster->line_hight / 2;
	g->ray->final_d *= cos(g->caster->ca);
}

// calls the functions above to get the horizontal ray
// and vertical ray and displays the one that is shorter
// for a smooth visualization
void	raycaster(t_game *g)
{
	g->ray->rays = 0;
	g->ray->ray_a = g->caster->pa - DGREE * 30;
	set_limit(g);
	replace_img(g);
	while (g->ray->rays < g->ray->n_of_rays)
	{
		check_horizontal_line(g);
		check_vertical_line(g);
		if (g->ray->dist_v < g->ray->dist_h)
		{
			g->ray->shade = 0.5;
			g->ray->ray_x = g->ray->ver_x;
			g->ray->ray_y = g->ray->ver_y;
			g->ray->final_d = g->ray->dist_v;
		}
		if (g->ray->dist_h < g->ray->dist_v)
		{
			g->ray->shade = 1;
			g->ray->ray_x = g->ray->hor_x;
			g->ray->ray_y = g->ray->hor_y;
			g->ray->final_d = g->ray->dist_h;
		}
		set_cosine_and_values(g);
		double	tx = (int)(g->ray->ray_x / 2.0) % 64;
		double	ty = g->ray->ty_off * g->ray->ty_step;
		g->dl->begin_x = g->ray->rays * (g->dis_w / g->ray->n_of_rays);
		for (int y = 0; y < g->caster->line_hight; y++) {
			int pixel = ((int)ty * g->wall_text->width + (int)tx) * g->wall_text->bytes_per_pixel;
			int color = (int)g->wall_text->pixels[pixel] << 24
			| (int)g->wall_text->pixels[pixel + 1] << 16
			| (int)g->wall_text->pixels[pixel + 2] << 8
			| (int)g->wall_text->pixels[pixel + 3];
			for (int i = 0; i < 12; i++)
				mlx_put_pixel(g->line, i + g->dl->begin_x, y + g->caster->line_offset, color);
			ty += g->ray->ty_step;
		}
		g->ray->ray_a += (DGREE / 2);
		set_limit(g);
		g->ray->rays++;
	}
}

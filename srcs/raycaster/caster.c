/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/11 12:25:18 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// deletes and replaces image for new line
void	replace_img(t_game *g)
{
	mlx_delete_image(g->mlx, g->line);
	g->line = mlx_new_image(g->mlx, g->width * DIMENS, g->height * DIMENS);
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

	ax = g->player->instances[0].x;
	ay = g->player->instances[0].y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
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
	while (g->ray->rays < 60)
	{
		check_horizontal_line(g);
		check_vertical_line(g);
		if (g->ray->dist_v < g->ray->dist_h)
		{
			g->ray->final_d = g->ray->dist_v;
			g->dl->color = 0x00F0FF;
		}
		if (g->ray->dist_h < g->ray->dist_v)
		{
			g->ray->final_d = g->ray->dist_h;
			g->dl->color = 0x00FFFF;
		}
		g->caster->line_hight = DIMENS * 640 / g->ray->final_d;
		if (g->caster->line_hight > 640)
			g->caster->line_hight = 640;
		g->caster->line_offset = 320 - g->caster->line_hight / 2;
		g->dl->begin_x = g->ray->rays * 16;
		g->dl->begin_y = g->caster->line_offset;
		g->dl->end_x = g->ray->rays * 16;
		g->dl->end_y = g->caster->line_hight + g->caster->line_offset;
		ft_draw_line_3D(g);
		g->ray->ray_a += DGREE;
		set_limit(g);
		g->ray->rays++;
	}
}

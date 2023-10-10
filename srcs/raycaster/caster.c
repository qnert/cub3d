/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/10 23:42:34 by njantsch         ###   ########.fr       */
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
			g->dl->end_x = g->ray->ver_x;
			g->dl->end_y = g->ray->ver_y;
		}
		if (g->ray->dist_h < g->ray->dist_v)
		{
			g->dl->end_x = g->ray->hor_x;
			g->dl->end_y = g->ray->hor_y;
		}
		g->dl->begin_x = g->player->instances[0].x + 5;
		g->dl->begin_y = g->player->instances[0].y + 5;
		ft_draw_line(g);
		g->ray->ray_a += DGREE;
		set_limit(g);
		g->ray->rays++;
	}
}

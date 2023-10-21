/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:45:04 by skunert           #+#    #+#             */
/*   Updated: 2023/10/21 16:52:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	draw_sky(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 40)
	{
		x = -1;
		while (++x < 120)
		{
			g->dl->x_off = rad_to_degree(g->caster->pa) * 2 + x;
			if (g->dl->x_off < 0)
				g->dl->x_off += 120;
			g->dl->x_off = g->dl->x_off % 120;
			g->dl->pixel = (y * 120 + g->dl->x_off)
				* g->ceiling_tex->bytes_per_pixel;
			g->dl->color = (int)g->ceiling_tex->pixels[g->dl->pixel] << 24
				| (int)g->ceiling_tex->pixels[g->dl->pixel + 1] << 16
				| (int)g->ceiling_tex->pixels[g->dl->pixel + 2] << 8
				| (int)g->ceiling_tex->pixels[g->dl->pixel + 3];
			scale_texture(g, x, y, 12);
		}
	}
}

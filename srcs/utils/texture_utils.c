/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:07:50 by skunert           #+#    #+#             */
/*   Updated: 2023/10/16 12:08:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_pixels_img(mlx_image_t *img, int max_x, int max_y, u_int32_t c)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			if (x == 0 || x == max_x - 1)
				mlx_put_pixel(img, x, y, 0x0000FF);
			else if (y == 0 || y == max_y - 1)
				mlx_put_pixel(img, x, y, 0x0000FF);
			else
				mlx_put_pixel(img, x, y, c);
			y++;
		}
		x++;
	}
}

void	scale_texture(t_game *g, int x, int y, int scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			mlx_put_pixel(g->line, i + x * scale, j + y * scale, g->dl->color);
			j++;
		}
		i++;
	}
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

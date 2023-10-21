/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:07:50 by skunert           #+#    #+#             */
/*   Updated: 2023/10/20 18:47:56 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

uint32_t	get_right_north_south_color(t_game *g)
{
	uint32_t	color;

	color = 0;
	if (g->ray->ray_a < M_PI && g->ray->ray_a > 0)
		color = (int)(g->wall_south_tex->pixels[g->dl->pixel]) << 24
			| (int)(g->wall_south_tex->pixels[g->dl->pixel + 1]) << 16
			| (int)(g->wall_south_tex->pixels[g->dl->pixel + 2]) << 8
			| (int)(g->wall_south_tex->pixels[g->dl->pixel + 3]);
	else
		color = (int)(g->wall_north_tex->pixels[g->dl->pixel]) << 24
			| (int)(g->wall_north_tex->pixels[g->dl->pixel + 1]) << 16
			| (int)(g->wall_north_tex->pixels[g->dl->pixel + 2]) << 8
			| (int)(g->wall_north_tex->pixels[g->dl->pixel + 3]);
	return (color);
}

uint32_t	get_right_west_east_color(t_game *g)
{
	uint32_t	color;

	color = 0;
	if (g->ray->ray_a < 3 * M_PI_2 && g->ray->ray_a > M_PI_2)
		color = (int)(g->wall_west_tex->pixels[g->dl->pixel]) << 24
			| (int)(g->wall_west_tex->pixels[g->dl->pixel + 1]) << 16
			| (int)(g->wall_west_tex->pixels[g->dl->pixel + 2]) << 8
			| (int)(g->wall_west_tex->pixels[g->dl->pixel + 3]);
	else
		color = (int)(g->wall_east_tex->pixels[g->dl->pixel]) << 24
			| (int)(g->wall_east_tex->pixels[g->dl->pixel + 1]) << 16
			| (int)(g->wall_east_tex->pixels[g->dl->pixel + 2]) << 8
			| (int)(g->wall_east_tex->pixels[g->dl->pixel + 3]);
	return (color);
}

uint32_t	get_right_wall_color(t_game *g)
{
	uint32_t	color;

	color = 0;
	if (g->caster->map[(int)g->ray->ray_y / DIMENS]
		[(int)g->ray->ray_x / DIMENS] == 'D')
		color = (int)(g->door_tex->pixels[g->dl->pixel]) << 24
			| (int)(g->door_tex->pixels[g->dl->pixel + 1]) << 16
			| (int)(g->door_tex->pixels[g->dl->pixel + 2]) << 8
			| (int)(g->door_tex->pixels[g->dl->pixel + 3]);
	else if (g->ray->shade == 0.5)
		color = get_right_west_east_color(g);
	else
		color = get_right_north_south_color(g);
	return (color);
}

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

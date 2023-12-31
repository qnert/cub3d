/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:09:23 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 13:50:40 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_draw_beer(t_game *g, int x, int y, int scale)
{
	while (x < g->ds->sx + scale / 2)
	{
		y = -1;
		g->ds->t_y = g->tex->coll_tex->height - 1;
		while (++y < scale)
		{
			g->dl->pixel = ((int)g->ds->t_y * g->tex->coll_tex->height
					+ (int)g->ds->t_x) * g->tex->coll_tex->bytes_per_pixel;
			g->dl->color = (int)(g->tex->coll_tex->pixels[g->dl->pixel]) << 24
				| (int)(g->tex->coll_tex->pixels[g->dl->pixel + 1]) << 16
				| (int)(g->tex->coll_tex->pixels[g->dl->pixel + 2]) << 8
				| (int)(g->tex->coll_tex->pixels[g->dl->pixel + 3]);
			if (x > 0 && g->ds->sy > g->dis_h / 2
				&& x < g->dis_w && g->ds->sy - y < g->dis_h
				&& g->dl->color != 0)
				mlx_put_pixel(g->line, x, g->ds->sy - y, g->dl->color);
			g->ds->t_y -= g->tex->coll_tex->height / (float)scale;
			if (g->ds->t_y < 0)
				g->ds->t_y = 0;
		}
		g->ds->t_x += (g->tex->coll_tex->height - 0.5) / (float)scale;
		if (g->ds->t_x >= g->tex->coll_tex->width)
			g->ds->t_x = g->tex->coll_tex->width - 1;
		x++;
	}
}

void	ft_draw_water(t_game *g, int x, int y, int scale)
{
	while (x < g->ds->sx + scale / 2)
	{
		y = -1;
		g->ds->t_y = g->tex->water_tex->height - 1;
		while (++y < scale)
		{
			g->dl->pixel = ((int)g->ds->t_y * g->tex->water_tex->height
					+ (int)g->ds->t_x) * g->tex->water_tex->bytes_per_pixel;
			g->dl->color = (int)(g->tex->water_tex->pixels[g->dl->pixel]) << 24
				| (int)(g->tex->water_tex->pixels[g->dl->pixel + 1]) << 16
				| (int)(g->tex->water_tex->pixels[g->dl->pixel + 2]) << 8
				| (int)(g->tex->water_tex->pixels[g->dl->pixel + 3]);
			if (x > 0 && g->ds->sy > g->dis_h / 2
				&& x < g->dis_w && g->ds->sy - y < g->dis_h
				&& g->dl->color != 0)
				mlx_put_pixel(g->line, x, g->ds->sy - y, g->dl->color);
			g->ds->t_y -= g->tex->water_tex->height / (float)scale;
			if (g->ds->t_y < 0)
				g->ds->t_y = 0;
		}
		g->ds->t_x += (g->tex->water_tex->height - 0.5) / (float)scale;
		if (g->ds->t_x >= g->tex->water_tex->width)
			g->ds->t_x = g->tex->water_tex->width - 1;
		x++;
	}
}

void	ft_draw_chest(t_game *g, int x, int y, int scale)
{
	while (x < g->ds->sx + scale / 2)
	{
		y = -1;
		g->ds->t_y = g->tex->chest_tex->height - 1;
		while (++y < scale)
		{
			g->dl->pixel = ((int)g->ds->t_y * g->tex->chest_tex->height
					+ (int)g->ds->t_x) * g->tex->chest_tex->bytes_per_pixel;
			g->dl->color = (int)(g->tex->chest_tex->pixels[g->dl->pixel]) << 24
				| (int)(g->tex->chest_tex->pixels[g->dl->pixel + 1]) << 16
				| (int)(g->tex->chest_tex->pixels[g->dl->pixel + 2]) << 8
				| (int)(g->tex->chest_tex->pixels[g->dl->pixel + 3]);
			if (x > 0 && g->ds->sy > g->dis_h / 2
				&& x < g->dis_w && g->ds->sy - y < g->dis_h
				&& g->dl->color != 0)
				mlx_put_pixel(g->line, x, g->ds->sy - y, g->dl->color);
			g->ds->t_y -= g->tex->chest_tex->height / (float)scale;
			if (g->ds->t_y < 0)
				g->ds->t_y = 0;
		}
		g->ds->t_x += (g->tex->chest_tex->height - 0.5) / (float)scale;
		if (g->ds->t_x >= g->tex->chest_tex->width)
			g->ds->t_x = g->tex->chest_tex->width - 1;
		x++;
	}
}

void	ft_draw_sprites(t_game *g)
{
	int	x;
	int	y;
	int	scale;

	scale = 16 * g->dis_w / g->ds->rot_b;
	x = g->ds->sx - scale / 2;
	y = -1;
	if (scale > 171)
		scale = 171;
	if (scale < 0)
		scale = 0;
	g->ds->t_x = 0;
	if (ft_distance(g, g->sp->x, g->sp->y) < 100 && g->sp->state == 1)
	{
		if (g->sp->type == 4 && ft_distance(g, g->sp->x, g->sp->y) < 75)
			g->game_over = 1;
		else if (g->sp->type != 4)
			g->sp->state = 0;
		increment_drunkness(g);
		decrement_drunkness(g);
	}
	if (ft_check_walls_sprite(g, (double)g->sp->x, (double)g->sp->y) == false
		&& g->sp->state == 1 && x + g->tex->chest_tex->width > 0
		&& g->ds->sy > g->dis_h / 2 && x < g->dis_w)
		check_sprite_type_for_draw(g, x, y, scale);
}

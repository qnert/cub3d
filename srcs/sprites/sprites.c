/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:52:24 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/25 18:04:26 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_check_walls_sprite(t_game *g)
{
	double	step_x;
	double	step_y;
	double	px;
	double	py;
	int		i;

	i = -1;
	step_x = (g->sp->x - g->pl_x) / DIMENS;
	step_y = (g->sp->y - g->pl_y) / DIMENS;
	px = g->pl_x;
	py = g->pl_y;
	while (++i < DIMENS)
	{
		g->caster->map_x = (int)(px / DIMENS);
		g->caster->map_y = (int)(py / DIMENS);
		if (g->caster->map_x >= 0 && g->caster->map_x < g->width
			&& g->caster->map_y >= 0 && g->caster->map_y < g->height)
			if (g->caster->map[g->caster->map_y][g->caster->map_x] == '1'
				|| g->caster->map[g->caster->map_y][g->caster->map_x] == 'D')
				return (true);
		px += step_x;
		py += step_y;
	}
	return (false);
}

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
				&& x < g->dis_w && g->ds->sy < g->dis_h
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
				&& x < g->dis_w && g->ds->sy < g->dis_h
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

void	increment_drunkness(t_game *g)
{
	if (g->sp->type == 2)
	{
		g->drunk += 0.1;
		if (g->drunk > 1.0)
			g->drunk = 1.0;
	}
}

void	decrement_drunkness(t_game *g)
{
	if (g->sp->type == 3)
	{
		g->drunk = 0;
	}
}

void	check_sprite_type_for_draw(t_game *g, int x, int y, int scale)
{
	if (g->sp->type == 2)
		ft_draw_beer(g, x, y, scale);
	if (g->sp->type == 3)
		ft_draw_water(g, x, y, scale);
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
		g->sp->state = 0;
		increment_drunkness(g);
		decrement_drunkness(g);
	}
	if (ft_check_walls_sprite(g) == false && g->sp->state == 1
		&& x > 0 && g->ds->sy > g->dis_h / 2
		&& x < g->dis_w && g->ds->sy < g->dis_h)
		check_sprite_type_for_draw(g, x, y, scale);
}

void	ft_set_values_sprites(t_game *g)
{
	t_sprite	*begin;

	begin = g->sp;
	while ((g->n_of_coll > 0 && g->sp) || (g->n_of_water > 0 && g->sp))
	{
		g->ds->sx = g->sp->x - g->pl_x;
		g->ds->sy = g->sp->y - g->pl_y;
		g->ds->sz = g->sp->z;
		g->ds->cosine = cos(g->caster->pa);
		g->ds->sine = sin(g->caster->pa);
		g->ds->rot_a = g->ds->sy * g->ds->cosine * 12
			- g->ds->sx * g->ds->sine * 12;
		g->ds->rot_b = g->ds->sx * g->ds->cosine + g->ds->sy * g->ds->sine;
		g->ds->sx = (g->ds->rot_a * 108.0 / g->ds->rot_b) + (g->dis_w / 2);
		g->ds->sy = (g->ds->sz * 108.0 / g->ds->rot_b) + (g->dis_h / 2);
		ft_draw_sprites(g);
		g->sp = g->sp->next;
	}
	g->sp = begin;
}

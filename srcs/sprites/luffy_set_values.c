/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luffy_set_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:19:23 by skunert           #+#    #+#             */
/*   Updated: 2023/11/03 17:51:25 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_luffy_colors_and_draw(t_game *g, int x, int y)
{
	g->dl->pixel = ((int)g->ds->t_y
			* g->luffy->animation[g->luffy->i]->height
			+ (int)g->ds->t_x) * g->luffy->animation
	[g->luffy->i]->bytes_per_pixel;
	g->dl->color = (int)(g->luffy->animation
		[g->luffy->i]->pixels[g->dl->pixel]) << 24
		| (int)(g->luffy->animation
		[g->luffy->i]->pixels[g->dl->pixel + 1]) << 16
		| (int)(g->luffy->animation
		[g->luffy->i]->pixels[g->dl->pixel + 2]) << 8
		| (int)(g->luffy->animation
		[g->luffy->i]->pixels[g->dl->pixel + 3]);
	if (x > 0 && g->ds->sy > g->dis_h / 2
		&& x < g->dis_w && g->ds->sy - y < g->dis_h
		&& g->dl->color != 0)
		mlx_put_pixel(g->line, x, g->ds->sy - y, g->dl->color);
}

int	ft_draw_luffy_tex_loop(t_game *g, int x, int scale)
{
	int	y;

	y = -1;
	g->ds->t_y = g->luffy->animation[g->luffy->i]->height - 1;
	while (++y < scale)
	{
		ft_get_luffy_colors_and_draw(g, x, y);
		g->ds->t_y -= g->luffy->animation[g->luffy->i]->height
			/ (float)scale;
		if (g->ds->t_y < 0)
			g->ds->t_y = 0;
	}
	if (g->ds->sy - y > g->dis_h)
		return (1);
	g->ds->t_x += (g->luffy->animation[g->luffy->i]->height
			- 0.5) / (float)scale;
	if (g->ds->t_x >= g->luffy->animation[g->luffy->i]->width)
		g->ds->t_x = g->luffy->animation[0]->width - 1;
	return (0);
}

void	ft_draw_luffy_tex(t_game *g, int x, int scale)
{
	if (g->luffy->i == 72)
		g->luffy->i = 0;
	if (g->luffy->check == 2)
		g->luffy->check = 0;
	while (x < g->ds->sx + scale / 2)
	{
		if (ft_draw_luffy_tex_loop(g, x, scale) == 1)
			break ;
		x++;
	}
	if (g->luffy->i < 72 && g->luffy->check == 0)
		g->luffy->i++;
	g->luffy->check++;
}

void	ft_draw_luffy(t_game *g)
{
	int	x;
	int	scale;

	scale = 64 * g->dis_w / g->ds->rot_b;
	x = g->ds->sx - scale / 2;
	if (scale > 654)
		scale = 654;
	if (scale < 0)
		scale = 0;
	g->ds->t_x = 0;
	if (ft_check_walls_sprite(g, (double)g->luffy->x,
			(double)g->luffy->y) == false && x
		+ g->luffy->animation[0]->width > 0 && g->ds->sy > g->dis_h / 2
		&& x < g->dis_w)
		ft_draw_luffy_tex(g, x, scale * 1.5);
}

void	ft_set_values_luffy(t_game *g)
{
	g->ds->sx = g->luffy->x - g->pl_x;
	g->ds->sy = g->luffy->y - g->pl_y;
	g->ds->sz = g->luffy->z;
	g->ds->cosine = cos(g->caster->pa);
	g->ds->sine = sin(g->caster->pa);
	g->ds->rot_a = g->ds->sy * g->ds->cosine * 12
		- g->ds->sx * g->ds->sine * 12;
	g->ds->rot_b = g->ds->sx * g->ds->cosine + g->ds->sy * g->ds->sine;
	g->ds->sx = (g->ds->rot_a * 108.0 / g->ds->rot_b) + (g->dis_w / 2);
	g->ds->sy = (g->ds->sz * 108.0 / g->ds->rot_b) + (g->dis_h / 2);
	ft_draw_luffy(g);
}

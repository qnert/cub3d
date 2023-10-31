/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zorro_set_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:19:23 by skunert           #+#    #+#             */
/*   Updated: 2023/10/31 14:34:17 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_zorro_colors_and_draw(t_game *g, int x, int y)
{
	g->dl->pixel = ((int)g->ds->t_y
			* g->zorro->animation[g->zorro->i]->height
			+ (int)g->ds->t_x) * g->zorro->animation
	[g->zorro->i]->bytes_per_pixel;
	g->dl->color = (int)(g->zorro->animation
		[g->zorro->i]->pixels[g->dl->pixel]) << 24
		| (int)(g->zorro->animation
		[g->zorro->i]->pixels[g->dl->pixel + 1]) << 16
		| (int)(g->zorro->animation
		[g->zorro->i]->pixels[g->dl->pixel + 2]) << 8
		| (int)(g->zorro->animation
		[g->zorro->i]->pixels[g->dl->pixel + 3]);
	if (x > 0 && g->ds->sy > g->dis_h / 2
		&& x < g->dis_w && g->ds->sy - y < g->dis_h
		&& g->dl->color != 0)
		mlx_put_pixel(g->line, x, g->ds->sy - y, g->dl->color);
}

void	ft_draw_zorro_tex(t_game *g, int x, int y, int scale)
{
	if (g->zorro->i == 17)
		g->zorro->i = 0;
	if (g->zorro->check == 2)
		g->zorro->check = 0;
	while (x < g->ds->sx + scale / 2)
	{
		y = -1;
		g->ds->t_y = g->zorro->animation[g->zorro->i]->height - 1;
		while (++y < scale)
		{
			ft_get_zorro_colors_and_draw(g, x, y);
			g->ds->t_y -= g->zorro->animation[g->zorro->i]->height
				/ (float)scale;
			if (g->ds->t_y < 0)
				g->ds->t_y = 0;
		}
		if (g->ds->sy - y > g->dis_h)
			break ;
		g->ds->t_x += (g->zorro->animation[g->zorro->i]->height
				- 0.5) / (float)scale;
		if (g->ds->t_x >= g->zorro->animation[g->zorro->i]->width)
			g->ds->t_x = g->zorro->animation[0]->width - 1;
		x++;
	}
	if (g->zorro->i < 17 && g->zorro->check == 0)
		g->zorro->i++;
	g->zorro->check++;
}

void	ft_draw_zorro(t_game *g)
{
	int	x;
	int	y;
	int	scale;

	scale = 64 * g->dis_w / g->ds->rot_b;
	x = g->ds->sx - scale / 2;
	y = -1;
	if (scale > 753)
		scale = 753;
	if (scale < 0)
		scale = 0;
	g->ds->t_x = 0;
	if (ft_check_walls_sprite(g, g->zorro->x, g->zorro->y) == false && x
		+ g->zorro->animation[0]->width > 0 && g->ds->sy > g->dis_h / 2
		&& x < g->dis_w)
		ft_draw_zorro_tex(g, x, y, scale);
}

void	ft_set_values_zorro(t_game *g)
{
	g->ds->sx = g->zorro->x - g->pl_x;
	g->ds->sy = g->zorro->y - g->pl_y;
	g->ds->sz = g->zorro->z;
	enemy_follow(g);
	if (ft_distance(g, g->zorro->x, g->zorro->y) < 125)
		g->game_over = 2;
	g->ds->cosine = cos(g->caster->pa);
	g->ds->sine = sin(g->caster->pa);
	g->ds->rot_a = g->ds->sy * g->ds->cosine * 12
		- g->ds->sx * g->ds->sine * 12;
	g->ds->rot_b = g->ds->sx * g->ds->cosine + g->ds->sy * g->ds->sine;
	g->ds->sx = (g->ds->rot_a * 108.0 / g->ds->rot_b) + (g->dis_w / 2);
	g->ds->sy = (g->ds->sz * 108.0 / g->ds->rot_b) + (g->dis_h / 2);
	ft_draw_zorro(g);
}

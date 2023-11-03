/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:52:24 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/03 21:20:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_check_walls_sprite(t_game *g, double x, double y)
{
	double	step_x;
	double	step_y;
	double	px;
	double	py;
	int		i;

	i = -1;
	step_x = (x - g->pl_x) / DIMENS;
	step_y = (y - g->pl_y) / DIMENS;
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
	if (g->sp->type == 4)
		ft_draw_chest(g, x, y, scale);
}

void	ft_set_values_sprites(t_game *g)
{
	g->begin = g->sp;
	while (g->sp)
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
	g->sp = g->begin;
}

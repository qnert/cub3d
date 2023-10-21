/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:52:24 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/21 17:01:11 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_sprites(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			mlx_put_pixel(g->line, j + g->ds->sx, i
				+ g->ds->sy, 0x000000FF);
	}
}

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

void	ft_set_values_sprites(t_game *g)
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
	if (g->ds->sx > 0 && g->ds->sy > g->dis_h / 2
		&& g->ds->sx < g->dis_w && g->ds->sy < g->dis_h
		&& ft_check_walls_sprite(g) == false)
		ft_draw_sprites(g);
}

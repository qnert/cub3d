/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/10 21:22:51 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

t_ray	*ray_init(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->ray = 0;
	ray->depoffield = 0;
	ray->ray_a = 0;
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->x_o = 0;
	ray->y_o = 0;
	ray->player_x = 0;
	ray->player_y = 0;
	ray->dist_h = 0;
	ray->dist_v = 0;
	ray->hor_x = 0;
	ray->hor_y = 0;
	ray->ver_x = 0;
	ray->ver_y = 0;
	return (ray);
}

t_draw_line	*draw_line_init(void)
{
	t_draw_line *dl;

	dl = malloc(sizeof(t_draw_line));
	dl->delta_x = 0;
	dl->delta_y = 0;
	dl->direction_x = 0;
	dl->direction_y = 0;
	dl->error = 0;
	dl->two_times_error = 0;
	dl->begin_x = 0;
	dl->begin_y = 0;
	dl->end_x = 0;
	dl->end_y = 0;
	return (dl);
}

t_cast	*caster_init(t_map *init)
{
	t_cast	*caster;

	caster = malloc(sizeof(t_cast));
	caster->pa = 3 * M_PI_2;
	caster->map_x = 0;
	caster->map_y = 0;
	caster->pd_x = 0;
	caster->pd_y = 0;
	caster->map = init->map;
	return (caster);
}

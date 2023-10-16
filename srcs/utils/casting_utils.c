/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/16 12:56:18 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rad_to_degree(double rad)
{
	int	deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

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
	ray->rays = 0;
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
	ray->final_d = 0;
	ray->n_of_rays = 480;
	return (ray);
}

t_draw_line	*draw_line_init(void)
{
	t_draw_line	*dl;

	dl = malloc(sizeof(t_draw_line));
	dl->tx = 0;
	dl->ty = 0;
	dl->dy = 0;
	dl->fix_ra = 0;
	dl->pixel = 0;
	dl->color = 0;
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
	if (check_component('N', init->map))
		caster->pa = 3 * M_PI_2;
	else if (check_component('W', init->map))
		caster->pa = 2 * M_PI_2;
	else if (check_component('S', init->map))
		caster->pa = M_PI_2;
	else
		caster->pa = 0;
	caster->map_x = 0;
	caster->map_y = 0;
	caster->pd_x = 0;
	caster->pd_y = 0;
	caster->pd_x_strafe = 0;
	caster->pd_y_strafe = 0;
	caster->line_hight = 0;
	caster->line_offset = 0;
	caster->x_off = 0;
	caster->y_off = 0;
	caster->x_off_strafe = 0;
	caster->y_off_strafe = 0;
	caster->map = init->map;
	return (caster);
}

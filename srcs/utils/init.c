/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/03 22:43:25 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*strct_init(char *file_path)
{
	t_map		*init;

	init = malloc(sizeof(t_map));
	init->error = 0;
	init->map_fd = open(file_path, O_RDONLY);
	if (!init->map_fd)
		return (init->error = 2, init);
	initialize_vars_to_null(init);
	init->map = NULL;
	if (get_input(init) == 1)
		return (init->error = 1, init);
	init->map = get_and_check_map(init->map_fd);
	if (init->map == NULL)
		return (init->error = 1, init);
	ft_allocate_helper_structs(init);
	return (init);
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

t_draw_sprite	*draw_sprite_init(void)
{
	t_draw_sprite	*ds;

	ds = malloc(sizeof(t_draw_sprite));
	ds->sx = 0;
	ds->sy = 0;
	ds->sz = 0;
	ds->cosine = 0;
	ds->sine = 0;
	ds->rot_a = 0;
	ds->rot_b = 0;
	return (ds);
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

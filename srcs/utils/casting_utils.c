/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/09 16:25:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	get_player_pos(t_map *m, t_cast *c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (m->map[i])
// 	{
// 		j = 0;
// 		while (m->map[i][j])
// 		{
// 			if (m->map[i][j] == 'E' || m->map[i][j] == 'W'
// 				|| m->map[i][j] == 'S' || m->map[i][j] == 'N')
// 			{
// 				c->pos_x = j;
// 				c->pos_y = i;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
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

t_cast_dist	*rc_distance_init()
{
	t_cast_dist	*rc_dist;

	rc_dist = malloc(sizeof(t_cast_dist));
	rc_dist->delta_dist_x = 0;
	rc_dist->delta_dist_y = 0;
	rc_dist->side_dist_x = 0;
	rc_dist->side_dist_y = 0;
	return (rc_dist);
}

t_cast_dir	*rc_direction_init()
{
	t_cast_dir	*rc_dir;

	rc_dir = malloc(sizeof(t_cast_dir));
	rc_dir->dir_x = 0;
	rc_dir->dir_y = 1;
	rc_dir->raydir_x = 0;
	rc_dir->raydir_y = 0;
	return (rc_dir);
}

t_cast	*caster_init(t_map *init)
{
	t_cast	*caster;

	caster = malloc(sizeof(t_cast));
	caster->pa = 2 * M_PI;
	caster->map_x = 0;
	caster->map_y = 0;
	caster->pd_x = 0;
	caster->pd_y = 0;
	caster->map = init->map;
	caster->dir = rc_direction_init();
	caster->dist = rc_distance_init();
	return (caster);
}

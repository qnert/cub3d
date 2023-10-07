/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/07 13:00:02 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_length_ray(t_cast *caster)
{
	caster->map_x = (int)caster->pos_x;
	caster->map_y = (int)caster->pos_y;
	if (caster->dir->raydir_x == 0)
		caster->dist->delta_dist_x = 1e30;
	else
		caster->dist->delta_dist_x = fabs(1 / caster->dir->raydir_x);
	if (caster->dir->raydir_y == 0)
		caster->dist->delta_dist_y = 1e30;
	else
		caster->dist->delta_dist_y = fabs(1 / caster->dir->raydir_y);
}

void	ft_raycasting_loop(t_cast *caster, int width)
{
	int	x;

	x = -1;
	while (++x < width)
	{
		caster->camera_x = 2 * x / (double)width - 1;
		caster->dir->raydir_x = caster->dir->dir_x + caster->plane_x * caster->camera_x;
		caster->dir->raydir_y = caster->dir->dir_y + caster->plane_y * caster->camera_x;
		calculate_length_ray(caster);
	}
}
void	raycaster(t_game *game)
{
	ft_raycasting_loop(game->caster, game->width);
}

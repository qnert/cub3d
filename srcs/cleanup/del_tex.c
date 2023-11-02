/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:28:43 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/02 19:50:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_clear_up_wall_tex(t_game *g, int i)
{
	if (i == 1)
		mlx_delete_texture(g->tex->wall_north_tex);
	if (i == 2)
	{
		mlx_delete_texture(g->tex->wall_north_tex);
		mlx_delete_texture(g->tex->wall_south_tex);
	}
	if (i == 3)
	{
		mlx_delete_texture(g->tex->wall_north_tex);
		mlx_delete_texture(g->tex->wall_south_tex);
		mlx_delete_texture(g->tex->wall_west_tex);
	}
	if (i == 4)
	{
		mlx_delete_texture(g->tex->wall_north_tex);
		mlx_delete_texture(g->tex->wall_south_tex);
		mlx_delete_texture(g->tex->wall_west_tex);
		mlx_delete_texture(g->tex->wall_east_tex);
	}
}

void	ft_clear_up_other_tex(t_game *g, int i)
{
	if (i >= 1 && FLOOR == 1)
		mlx_delete_texture(g->tex->floor_tex);
	if (i >= 2 && SKY == 1)
		mlx_delete_texture(g->tex->ceiling_tex);
	if (i >= 3)
		mlx_delete_texture(g->tex->door_tex);
	if (i >= 4)
		mlx_delete_texture(g->tex->coll_tex);
	if (i == 5)
		mlx_delete_texture(g->tex->water_tex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:27:19 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/02 20:19:17 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_luffy_zorro(t_map *map)
{
	map->game->luffy->i = -1;
	while (++map->game->luffy->i < 72)
		mlx_delete_texture(map->game->luffy->animation
		[map->game->luffy->i]);
	free(map->game->luffy->animation);
	free(map->game->luffy);
	map->game->zorro->i = -1;
	while (++map->game->zorro->i < 17)
		mlx_delete_texture(map->game->zorro->animation
		[map->game->zorro->i]);
	free(map->game->zorro->animation);
	free(map->game->zorro);
}

void	ft_terminate_struct_helper(t_map *map)
{
	if (map->error == 0 || map->error == 3)
		ft_free_luffy_zorro(map);
	if (map->error == 0)
	{
		if (SKY == 1)
			mlx_delete_texture(map->game->tex->ceiling_tex);
		if (FLOOR == 1)
			mlx_delete_texture(map->game->tex->floor_tex);
		mlx_delete_texture(map->game->tex->wall_north_tex);
		mlx_delete_texture(map->game->tex->wall_south_tex);
		mlx_delete_texture(map->game->tex->wall_east_tex);
		mlx_delete_texture(map->game->tex->wall_west_tex);
		mlx_delete_texture(map->game->tex->door_tex);
		mlx_delete_texture(map->game->tex->coll_tex);
		mlx_delete_texture(map->game->tex->chest_tex);
		mlx_delete_texture(map->game->tex->water_tex);
	}
	if (map->error == 0 || map->error == 3)
		free(map->game->tex);
	if (map->map != NULL)
		free(map->game);
	free(map);
}

void	ft_terminate_struct(t_map *map)
{
	if (map->texture_path_no)
		free(map->texture_path_no);
	if (map->texture_path_ea)
		free(map->texture_path_ea);
	if (map->texture_path_we)
		free(map->texture_path_we);
	if (map->texture_path_so)
		free(map->texture_path_so);
	if (map->error != 2)
		close(map->map_fd);
	if (map->map != NULL)
	{
		free_arr(map->map);
		free(map->game->ray);
		free(map->game->caster);
		free(map->game->dl);
		free(map->game->ds);
		free_lst_sprites(map->game->sp);
	}
	ft_terminate_struct_helper(map);
}

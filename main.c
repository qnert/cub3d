/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:17:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/23 17:35:48 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_terminate_struct_helper(t_map *map)
{
	if (map->error == 0)
	{
		mlx_delete_texture(map->game->tex->ceiling_tex);
		mlx_delete_texture(map->game->tex->wall_north_tex);
		mlx_delete_texture(map->game->tex->wall_south_tex);
		mlx_delete_texture(map->game->tex->wall_east_tex);
		mlx_delete_texture(map->game->tex->wall_west_tex);
		mlx_delete_texture(map->game->tex->door_tex);
		mlx_delete_texture(map->game->tex->floor_tex);
		mlx_delete_texture(map->game->tex->coll_tex);
	}
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
		if (map->n_of_coll > 0)
			free_lst_sprites(map->game->sp);
	}
	ft_terminate_struct_helper(map);
}

int	main(int argc, char **argv)
{
	int		check;
	t_map	*map;

	if (argc != 2)
		return (printf("Error\nwrong amount of arguments\n"), 1);
	check = ft_check_file_type(argv[1]);
	if (check == 0)
		return (printf("Error\n"), 1);
	map = strct_init(argv[1]);
	if (map->error == 1 || map->error == 2)
		return (ft_terminate_struct(map), 1);
	map->error = 0;
	game_init(map);
	ft_terminate_struct(map);
	return (0);
}

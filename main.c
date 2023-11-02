/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:17:12 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 20:22:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	int		check;
	t_map	*map;

	if (argc != 2)
		return (printf("Error\nwrong amount of arguments\n"), 1);
	check = ft_check_file_type(argv[1]);
	if (check == 0)
		return (printf("Error\n"), 1);
	while (1)
	{
		map = strct_init(argv[1]);
		if (map->error > 0)
			return (ft_terminate_struct(map), 1);
		game_init(map);
		if (map->error > 0)
			return (ft_terminate_struct(map), 1);
		if (map->game->game_over != 3)
		{
			ft_terminate_struct(map);
			break ;
		}
		ft_terminate_struct(map);
	}
	// system("leaks cub3D");
	return (0);
}

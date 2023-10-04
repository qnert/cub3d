/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:17:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/04 16:45:03 by njantsch         ###   ########.fr       */
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
		printf("Error\n");
	map = strct_init(argv[1]);
	if (map->error == 1)
		return (1);
	map->error = 0;
	return (0);
}

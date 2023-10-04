/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:44:05 by skunert           #+#    #+#             */
/*   Updated: 2023/10/04 17:03:14 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**get_and_check_map(int fd)
{
	char	**map;

	map = get_map(fd);
	if (map == NULL)
		return (NULL);
	if (check_map(map) == false)
		return (free_arr(map), NULL);
	return (map);
}

// bool	check_end_walls(char **map)
// {
// 	int	i;
// 	int	tmp;

// 	i = 0;
// 	tmp = 0;
// 	while (map[i])
// 	{
// 		if (map[i + 1] && ft_strlen(map[i]) > ft_strlen(map[i + 1]))
// 		{
// 			tmp = ft_strlen(map[i]) - ft_strlen(map[i + 1]) - 1;
// 			while (map[tmp])
// 			{
// 				if (map[tmp] != '1' || is_whitespace(map[i]))
// 					return (false);
// 				tmp++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (true);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:21:20 by skunert           #+#    #+#             */
/*   Updated: 2023/10/04 17:48:42 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_component(char c, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	check_player_pos(char **map)
{
	if (check_component('N', map) == 1 && check_component('S', map) == 0
		&&check_component('E', map) == 0 && check_component('W', map) == 0)
		return ('N');
	else if (check_component('S', map) == 1 && check_component('N', map) == 0
		&&check_component('E', map) == 0 && check_component('W', map) == 0)
		return ('S');
	else if (check_component('E', map) == 1 && check_component('S', map) == 0
		&&check_component('N', map) == 0 && check_component('W', map) == 0)
		return ('E');
	else if (check_component('W', map) == 1 && check_component('S', map) == 0
		&&check_component('E', map) == 0 && check_component('N', map) == 0)
		return ('W');
	return ('F');
}

bool	check_invalid_component(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_component(map[i][j]) && !is_whitespace(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	complete_component_check(char **map)
{
	if (!check_map(map))
		return (false);
	if (!check_invalid_component(map))
		return (ft_error_msg("Invalid map component found\n"), false);
	if (check_player_pos(map) == 'F')
		return (ft_error_msg("Invalid player position\n"), false);
	return (true);
}

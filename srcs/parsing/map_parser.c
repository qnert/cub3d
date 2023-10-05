/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:18:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/05 11:50:11 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_side_line(char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (!is_whitespace(map[index][i]))
			if (map[index][i] != '1')
				return (false);
		i++;
	}
	return (true);
}

bool	check_middle_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (is_whitespace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (false);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_whitespace_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_whitespace(map[i][j]))
			{
				if (i > 0 && !is_valid_border(map[i - 1][j]))
					return (false);
				if (map[i + 1] && !is_valid_border(map[i + 1][j]))
					return (false);
				if (j > 0 && !is_valid_border(map[i][j - 1]))
					return (false);
				if (!is_valid_border(map[i][j + 1]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(char **map)
{
	if (check_side_line(map, 0) == false)
		return (ft_error_msg("First line of the map is wrong\n"), false);
	if (check_side_line(map, ft_matrixlen(map) - 1) == false)
		return (ft_error_msg("Last line of the map is wrong\n"), false);
	if (check_middle_lines(map) == false)
		return (ft_error_msg("One middle line of the map is wrong\n"), false);
	if (check_whitespace_border(map) == false)
		return (ft_error_msg("The map isn't surrounded by '1's\n"), false);
	if (check_end_walls_a(map) == false || check_end_walls_b(map) == false)
		return (ft_error_msg("The map is not surrounded by '1's\n"), false);
	return (true);
}

char	**get_map(int map_fd)
{
	char	*line;
	char	*buff;
	char	**map;

	buff = ft_strdup("");
	line = get_next_line(map_fd);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(map_fd);
	}
	while (line != NULL)
	{
		buff = ft_strjoin_free(buff, line);
		if (buff == NULL
			|| line[0] == '\n')
			return (ft_error_msg("New line inside the map\n"), NULL);
		free(line);
		line = get_next_line(map_fd);
	}
	map = ft_split(buff, '\n');
	if (map == NULL)
		return (free(buff), NULL);
	return (free(buff), map);
}

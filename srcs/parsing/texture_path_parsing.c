/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:41:30 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/04 13:02:33 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_input(t_map *init)
{
	char	*line;
	char	*tmp;

	tmp = get_next_line(init->map_fd);
	if (tmp == NULL)
		return (printf("Error\ncouldn't read from file\n"), 1);
	line = ft_strtrim(tmp, " \t");
	free(tmp);
	while (line != NULL)
	{
		if (check_line(init, line) == 1)
			return (free(line), 1);
		free(line);
		if (init->texture_path_ea && init->texture_path_no
			&& init->texture_path_so && init->texture_path_we
			&& check_rgb_validity(init) == 0)
			break ;
		tmp = get_next_line(init->map_fd);
		if (tmp == NULL)
			return (printf("Error\n file end reached in parsing\n"), 1);
		line = ft_strtrim(tmp, " \t");
		free(tmp);
	}
	return (0);
}

bool	check_identifier(char *line, int check)
{
	if (check == 1 && (ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "NO	", 3) == 0
			|| ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "SO	", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "WE	", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "EA	", 3) == 0))
		return (true);
	else if (check == 2 && (ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0
			|| ft_strncmp(line, "F	", 2) == 0
			|| ft_strncmp(line, "C	", 2) == 0))
		return (true);
	return (false);
}

int	check_line(t_map *init, char *line)
{
	int	nl_check;

	nl_check = 0;
	if (line[0] == '\n')
		nl_check = 1;
	if (nl_check == 0 && check_identifier(line, 1) == true)
	{
		if (get_texture_path(init, line) == 1)
			return (1);
	}
	else if (nl_check == 0 && check_identifier(line, 2) == true)
	{
		if (check_rgb(init, line) == 1)
			return (1);
	}
	else
		if (nl_check == 0)
			return (ft_printf("Error\nnot a valid identifier\n"), 1);
	return (0);
}

int	get_texture_path(t_map *init, char *trmd_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (trmd_line[i] != ' ')
		i++;
	while (trmd_line[i] == ' ')
		i++;
	while (trmd_line[i + j])
		j++;
	if (ft_strncmp(trmd_line, "NO", 2) == 0 && !init->texture_path_no)
		init->texture_path_no = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "SO", 2) == 0 && !init->texture_path_so)
		init->texture_path_so = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "WE", 2) == 0 && !init->texture_path_we)
		init->texture_path_we = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "EA", 2) == 0 && !init->texture_path_ea)
		init->texture_path_ea = ft_substr(trmd_line, i, j - 1);
	else
		return (printf("Error\nduplicate identifier\n"), 1);
	return (0);
}

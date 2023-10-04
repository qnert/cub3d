/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/03 21:32:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*strct_init(char *file_path)
{
	t_map	*init;
	int	i;

	i = -1;
	init = malloc(sizeof(t_map));
	init->error = 0;
	init->map_fd = open(file_path, O_RDONLY);
	if (!init->map_fd)
		return (init->error = 2, init);
	init->texture_path_no = NULL;
	init->texture_path_so = NULL;
	init->texture_path_we = NULL;
	init->texture_path_ea = NULL;
	while (++i < 3)
	{
		init->floor_rgb[i] = -1;
		init->ceiling_rgb[i] = -1;
	}
	if (get_input(init) == 1)
		return (init->error = 1, init);
	init->map = NULL;
	return (init);
}

int	get_input(t_map *init)
{
	char	*line;
	char	*tmp;

	tmp = get_next_line(init->map_fd);
	if (tmp == NULL)
		return (printf("Error\ncouldn't read from file\n"), 1);
	line = ft_strtrim(tmp, " ");
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
		line = ft_strtrim(tmp, " ");
		free(tmp);
	}
	return (0);
}

int	check_line(t_map *init, char *line)
{
	int	nl_check;

	nl_check = 0;
	if (line[0] == '\n')
		nl_check = 1;
	if (nl_check == 0 &&
		(ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0))
	{
		if (get_texture_path(init, line) == 1)
			return (1);
	}
	else if (nl_check == 0 && (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0))
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
	if (ft_strncmp(trmd_line, "NO ", 3) == 0 && !init->texture_path_no)
		init->texture_path_no = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "SO ", 3) == 0 && !init->texture_path_so)
		init->texture_path_so = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "WE ", 3) == 0 && !init->texture_path_we)
		init->texture_path_we = ft_substr(trmd_line, i, j - 1);
	else if (ft_strncmp(trmd_line, "EA ", 3) == 0 && !init->texture_path_ea)
		init->texture_path_ea = ft_substr(trmd_line, i, j - 1);
	else
		return (printf("Error\nduplicate identifier\n"), 1);
	return (0);
}

int	check_rgb(t_map *init, char *trmd_line)
{
	char	**rgb;
	int		i;
	int		j;

	i = -1;
	j = -1;
	rgb = ft_split(trmd_line + 2, ',');
	if (ft_matrixlen(rgb) != 3)
		return (free_arr(rgb), printf("Error\nwrong rgb format\n"), 1);
	while (rgb[++i])
	{
		while (rgb[i][++j])
			if (ft_isdigit(rgb[i][j]) == 0)
				return (free_arr(rgb), printf("Error\nno valid rgb nbr\n"), 1);
		if (ft_strlen(rgb[i]) > 3)
		{
			free_arr(rgb);
			return (printf("Error\nnot a valid rgb range\n"), 1);
		}
	}
	if (get_rgb(init, trmd_line, rgb) == 1)
		return (free_arr(rgb), 1);
	free_arr(rgb);
	return (0);
}

int	get_rgb(t_map *init, char *id, char **rgb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) >= 0 && ft_atoi(rgb[i]) <= 255)
		{
			if ((id[0] == 'F' && init->floor_rgb[j] != -1)
				|| (id[0] == 'C' && init->ceiling_rgb[k] != -1))
				return (printf("Error\nduplicate rgb identifier\n"), 1);
			if (id[0] == 'F' && init->floor_rgb[j] == -1)
				init->floor_rgb[j++] = ft_atoi(rgb[i]);
			else if (id[0] == 'C' && init->ceiling_rgb[k] == -1)
				init->ceiling_rgb[k++] = ft_atoi(rgb[i]);
		}
		else
			return (printf("Error\nnot a valid rgb range\n"), 1);
		i++;
	}
	return (0);
}

int	check_rgb_validity(t_map *init)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (init->floor_rgb[i] == -1 || init->ceiling_rgb[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

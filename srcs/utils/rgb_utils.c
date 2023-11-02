/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:34:30 by skunert           #+#    #+#             */
/*   Updated: 2023/11/02 19:14:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	check_rgb_loop(char **rgb, char *trmd, int i, int j)
{
	while (rgb[i][++j])
		if (ft_isdigit(rgb[i][j]) == 0 && rgb[i][j] != '\n')
			return (free_arr(rgb), free(trmd),
			printf("Error\nno valid rgb nbr\n"), 1);
	if (ft_strlen(rgb[i]) > 3)
	{
		free_arr(rgb);
		return (free(trmd), printf("Error\nwrong rgb size\n"), 1);
	}
	return (0);
}

int	check_rgb(t_map *init, char *line)
{
	char	**rgb;
	char	*trmd;
	int		i;
	int		j;

	i = -1;
	trmd = ft_strtrim(line, "\n");
	rgb = ft_split(trmd + 2, ',');
	if (ft_matrixlen(rgb) != 3)
		return (free_arr(rgb), free(trmd), printf("Error\nrgb format\n"), 1);
	while (rgb[++i])
	{
		j = -1;
		check_rgb_loop(rgb, trmd, i, j);
	}
	if (get_rgb(init, trmd, rgb) == 1)
		return (free_arr(rgb), free(trmd), 1);
	return (free_arr(rgb), free(trmd), 0);
}

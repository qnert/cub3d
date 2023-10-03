/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:23:13 by skunert           #+#    #+#             */
/*   Updated: 2023/10/03 18:07:59 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_check_file_type(char *str)
{
	int		i;
	char	**split_path;
	char	**split_file;

	i = 0;
	split_path = ft_split(str, '/');
	while (split_path[i] != NULL)
		i++;
	i--;
	split_file = ft_split(split_path[i], '.');
	free_arr(split_path);
	i = 0;
	while (split_file[i] != NULL)
		i++;
	i--;
	if (ft_strncmp(split_file[i], "cub", 3) != 0)
		return (free_arr(split_file), 0);
	free_arr(split_file);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/03 16:24:54 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	strct_init(char *file_path)
{
	t_map	init;

	init.map_fd = open(file_path, O_RDONLY);
	if (!init.map_fd)
		return (init);
	init.map = get_map(file_path);
	init.texture_path_no = get_texture_path("NO");
	return (init);
}

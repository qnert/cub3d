/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:36:51 by skunert           #+#    #+#             */
/*   Updated: 2023/10/19 15:40:22 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

uint32_t	ft_check_color_walls(t_game *g, float x, float y)
{
	if (x >= 0 && y >= 0 && x <= g->width
		* DIMENS && y <= g->height * DIMENS
		&& g->caster->map[(int)y / DIMENS][(int)x / DIMENS] == 'D')
		return (0x3498DBFF);
	else if (x >= 0 && y >= 0 && x <= g->width
		* DIMENS && y <= g->height * DIMENS
		&& g->caster->map[(int)y / DIMENS][(int)x / DIMENS] == '1')
		return (0x515A5AFF);
	return (0);
}

void	ft_fill_minimap_walls(t_game *g)
{
	float	x;
	float	y;
	int		c;
	int		mini_x;
	int		mini_y;

	y = g->pl_y - 5 * DIMENS;
	mini_y = 0;
	while (mini_y < 200)
	{
		x = g->pl_x - 5 * DIMENS;
		mini_x = 0;
		while (mini_x < 200)
		{
			c = ft_check_color_walls(g, x, y);
			if (c != 0)
				mlx_put_pixel(g->minimap, mini_x, mini_y, c);
			mini_x++;
			x += 6.4;
		}
		mini_y++;
		y += 6.4;
	}
	ft_fill_miniplayer(g, 98, 98);
}

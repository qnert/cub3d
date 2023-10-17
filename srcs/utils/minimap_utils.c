/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:26 by skunert           #+#    #+#             */
/*   Updated: 2023/10/17 19:05:40 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_miniplayer(t_game *g, int x, int y)
{
	int	start_x;
	int	start_y;

	start_y = y;
	while (start_y < 83)
	{
		start_x = x;
		while (start_x < 83)
		{
			mlx_put_pixel(g->minimap, start_x, start_y, 0xF1C40FFF);
			start_x++;
		}
		start_y++;
	}
}

int	check_free_char(char c)
{
	if (ft_strchr("0XNWSE", c))
		return (1);
	return (0);
}

uint32_t	ft_check_color(t_game *g, float x, float y)
{
	if (x >= 0 && y >= 0 && x <= 33 * DIMENS && y <= 14 * DIMENS
		&& (check_free_char(g->caster->map[(int)y / DIMENS][(int)x / DIMENS])))
		return (0xEAEDEDFF);
	else if (x >= 0 && y >= 0 && x <= g->width
		* DIMENS && y <= g->height * DIMENS
		&& g->caster->map[(int)y / DIMENS][(int)x / DIMENS] == 'D')
		return (0x3498DBFF);
	else
		return (0x515A5AFF);
}

void	ft_fill_minimap(t_game *g)
{
	float	x;
	float	y;
	int		c;
	int		mini_x;
	int		mini_y;

	y = g->pl_y - 4 * DIMENS;
	mini_y = 0;
	while (mini_y < 160)
	{
		x = g->pl_x - 4 * DIMENS;
		mini_x = 0;
		while (mini_x < 160)
		{
			c = ft_check_color(g, x, y);
			mlx_put_pixel(g->minimap, mini_x, mini_y, c);
			mini_x++;
			x += 6.4;
		}
		mini_y++;
		y += 6.4;
	}
	ft_fill_miniplayer(g, 78, 78);
}

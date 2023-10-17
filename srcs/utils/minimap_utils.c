/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:26 by skunert           #+#    #+#             */
/*   Updated: 2023/10/17 18:37:14 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_minispace(t_game *g, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + 20)
	{
		x = start_x;
		while (x < start_x + 20)
		{
			mlx_put_pixel(g->minimap, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_fill_miniplayer(t_game *g, int x, int y)
{
	int	start_x;
	int	start_y;

	start_y = y;
	while (start_y < 90)
	{
		start_x = x;
		while (start_x < 90)
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

uint32_t	ft_check_color(t_game *g, int x, int y)
{
	if (x >= 0 && y >= 0
		&& (check_free_char(g->caster->map[y / DIMENS][x / DIMENS])))
		return (0xEAEDEDFF);
	else if (x >= 0 && y >= 0
		&& g->caster->map[y / DIMENS][x / DIMENS] == 'D')
		return (0x3498DBFF);
	else
		return (0x515A5AFF);
}

void	ft_fill_minimap(t_game *g)
{
	int	x;
	int	y;
	int	c;
	int	mini_x;
	int	mini_y;

	y = g->pl_y - 4 * DIMENS;
	mini_y = 0;
	while (mini_y < 160)
	{
		x = g->pl_x - 4 * DIMENS;
		mini_x = 0;
		while (mini_x < 160)
		{
			c = ft_check_color(g, x, y);
			ft_fill_minispace(g, mini_x, mini_y, c);
			mini_x += 20;
			x += DIMENS;
		}
		mini_y += 20;
		y += DIMENS;
	}
	ft_fill_miniplayer(g, 85, 85);
}

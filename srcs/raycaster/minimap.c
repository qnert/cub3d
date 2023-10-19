/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:26 by skunert           #+#    #+#             */
/*   Updated: 2023/10/19 17:22:09 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_game *g)
{
	g->dl->begin_x = 98;
	g->dl->begin_y = 98;
	g->dl->end_x = (g->ray->ray_x - (g->pl_x - 5 * DIMENS)) / DIMENS * 20;
	g->dl->end_y = (g->ray->ray_y - (g->pl_y - 5 * DIMENS)) / DIMENS * 20;
	ft_draw_line(g);
}

void	ft_fill_miniplayer(t_game *g, int x, int y)
{
	for (int j = 0; j < 5; j++)
		for(int i = 0; i < 5; i++)
			mlx_put_pixel(g->minimap, x + i, y + j, 0xF1C40FFF);
}

int	check_free_char(char c)
{
	if (ft_strchr("0XNWSEP", c))
		return (1);
	return (0);
}

uint32_t	ft_check_color(t_game *g, float x, float y)
{
	if (x >= 0 && y >= 0 && x <= 33 * DIMENS && y <= 14 * DIMENS
		&& (check_free_char(g->caster->map[(int)y / DIMENS][(int)x / DIMENS])))
		return (0xEAEDEDFF);
	return (0);
}

void	ft_fill_minimap(t_game *g)
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
			c = ft_check_color(g, x, y);
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

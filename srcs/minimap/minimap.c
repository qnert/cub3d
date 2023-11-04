/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:26 by skunert           #+#    #+#             */
/*   Updated: 2023/11/04 20:08:37 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_game *g)
{
	g->dl->begin_x = 98;
	g->dl->begin_y = 98;
	g->dl->end_x = (g->ray->ray_x - (g->pl_x - 5 * DIMENS)) / DIMENS * 20;
	g->dl->end_y = (g->ray->ray_y - (g->pl_y - 5 * DIMENS)) / DIMENS * 20;
	ft_draw_line(g, -1);
}

void	ft_fill_miniplayer(t_game *g, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			mlx_put_pixel(g->minimap_rc, x + j, y + i, 0xF1C40FFF);
	}
}

int	check_free_char(char c)
{
	if (ft_strchr("0XNWSE32LZ4", c))
		return (1);
	return (0);
}

uint32_t	ft_check_color(t_game *g, double x, double y)
{
	if (x >= 0 && y >= 0 && y <= g->height * DIMENS
		&& x <= ft_strlen(g->caster->map[(int)y / DIMENS]) * DIMENS)
	{
		if (check_free_char(g->caster->map[(int)y / DIMENS][(int)x / DIMENS]))
			return (0xEAEDEDFF);
		else if (g->caster->map[(int)y / DIMENS][(int)x / DIMENS] == 'D')
			return (0x3498DBFF);
		else if (g->caster->map[(int)y / DIMENS][(int)x / DIMENS] == '1')
			return (0x515A5AFF);
	}
	return (0);
}

void	ft_fill_minimap(t_game *g)
{
	double	x;
	double	y;
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

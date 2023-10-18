/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:26 by skunert           #+#    #+#             */
/*   Updated: 2023/10/18 14:53:11 by skunert          ###   ########.fr       */
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

	y = g->pl_y - 5 * DIMENS;
	mini_y = 0;
	while (mini_y < 200)
	{
		x = g->pl_x - 5 * DIMENS;
		mini_x = 0;
		while (mini_x < 200)
		{
			c = ft_check_color(g, x, y);
			mlx_put_pixel(g->minimap, mini_x, mini_y, c);
			mini_x++;
			x += 6.4;
		}
		mini_y++;
		y += 6.4;
	}
	ft_fill_miniplayer(g, 98, 98);
}

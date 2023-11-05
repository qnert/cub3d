/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:42 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/04 20:01:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_dl_assign_values(t_game *game)
{
	game->dl->delta_x = ft_abs(game->dl->end_x - game->dl->begin_x);
	game->dl->delta_y = ft_abs(game->dl->end_y - game->dl->begin_y);
	if (game->dl->begin_x < game->dl->end_x)
		game->dl->direction_x = 1;
	else
		game->dl->direction_x = -1;
	if (game->dl->begin_y < game->dl->end_y)
		game->dl->direction_y = 1;
	else
		game->dl->direction_y = -1;
	game->dl->error = game->dl->delta_x - game->dl->delta_y;
}

void	ft_draw_line(t_game *game, int i)
{
	ft_dl_assign_values(game);
	while (1)
	{
		if ((game->dl->begin_x == game->dl->end_x && game->dl->begin_y
				== game->dl->end_y) || (game->dl->begin_x > 197
				|| game->dl->begin_y > 197 || game->dl->begin_x < 0
				|| game->dl->begin_y < 0))
			break ;
		i = -1;
		while (++i < 3)
			mlx_put_pixel(game->minimap_rc, game->dl->begin_x + i,
				game->dl->begin_y, 0xF0F00FFF);
		game->dl->two_times_error = 2 * game->dl->error;
		if (game->dl->two_times_error > -game->dl->delta_y)
		{
			game->dl->error -= game->dl->delta_y;
			game->dl->begin_x += game->dl->direction_x;
		}
		if (game->dl->two_times_error < game->dl->delta_x)
		{
			game->dl->error += game->dl->delta_x;
			game->dl->begin_y += game->dl->direction_y;
		}
	}
}

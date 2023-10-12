/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:42 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/12 12:25:58 by skunert          ###   ########.fr       */
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

void	ft_draw_line_3D(t_game *game)
{
	int	i;

	ft_dl_assign_values(game);
	while (1)
	{
		i = -1;
		while (++i < 17)
			mlx_put_pixel(game->line, game->dl->begin_x + i, game->dl->begin_y, game->dl->color);
		if (game->dl->begin_x == game->dl->end_x && game->dl->begin_y == game->dl->end_y)
			break;
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

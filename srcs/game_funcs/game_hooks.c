/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/09 16:40:54 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_line(t_game *game)
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
	mlx_delete_image(game->mlx, game->line);
	game->line = mlx_new_image(game->mlx, game->width * DIMENS, game->height * DIMENS);
	mlx_image_to_window(game->mlx, game->line, 0, 0);
	while (1)
	{
		mlx_put_pixel(game->line, game->dl->begin_x, game->dl->begin_y, 0xFFF00FFF);
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

void	ft_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player->instances[0].y -= 3;
		game->line->instances[0].y -= 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player->instances[0].y += 3;
		game->line->instances[0].y += 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player->instances[0].x += 3;
		game->line->instances[0].x += 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player->instances[0].x -= 3;
		game->line->instances[0].x -= 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.1;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
		game->caster->pd_x = cos(game->caster->pa) * 5;
		game->caster->pd_y = sin(game->caster->pa) * 5;
		game->dl->begin_x = game->player->instances[0].x + 5;
		game->dl->begin_y = game->player->instances[0].y + 5;
		game->dl->end_x = game->player->instances[0].x + game->caster->pd_x * 4;
		game->dl->end_y = game->player->instances[0].y + game->caster->pd_y * 4;
		ft_draw_line(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.1;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
		game->caster->pd_x = cos(game->caster->pa) * 5;
		game->caster->pd_y = sin(game->caster->pa) * 5;
		game->dl->begin_x = game->player->instances[0].x + 5;
		game->dl->begin_y = game->player->instances[0].y + 5;
		game->dl->end_x = game->player->instances[0].x + game->caster->pd_x * 4;
		game->dl->end_y = game->player->instances[0].y + game->caster->pd_y * 4;
		ft_draw_line(game);
	}
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	// raycaster(game);
	ft_move(game);
}

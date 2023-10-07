/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/07 15:30:28 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player->instances[0].y -= 5;
		game->line->instances[0].y -= 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player->instances[0].y += 5;
		game->line->instances[0].y += 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player->instances[0].x += 5;
		game->line->instances[0].x += 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		// game->player->instances[0].x -= 5;
		// game->line->instances[0].x -= 5;
		game->caster->pa -= 0.1;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
		game->caster->pd_x = cos(game->caster->pa) * 5;
		game->caster->pd_y = sin(game->caster->pa) * 5;
		mlx_image_to_window(game->mlx, game->line,
			game->line->instances[0].x + game->caster->pd_x * 5, game->line->instances[0].y + game->caster->pd_y * 5);
	}
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	// raycaster(game);
	ft_move(game);
}

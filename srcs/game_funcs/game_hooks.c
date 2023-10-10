/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/10 22:59:19 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.04;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
}

void	ft_rotate_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.04;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
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
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	ft_move(game);
	raycaster(game);
	ft_rotate_left(game);
	ft_rotate_right(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:48:12 by skunert           #+#    #+#             */
/*   Updated: 2023/10/12 10:06:12 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.05;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
}

void	ft_rotate_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.05;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
	}
}

void	ft_move(t_game *game)
{
	game->caster->pd_x = cos(game->caster->pa) * 3;
	game->caster->pd_y = sin(game->caster->pa) * 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->pl_x += cos(game->caster->pa) * 3;
		game->pl_y += sin(game->caster->pa) * 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->pl_x -= cos(game->caster->pa) * 3;
		game->pl_y -= sin(game->caster->pa) * 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->pl_x += cos(game->caster->pa + M_PI_2) * 3;
		game->pl_y += sin(game->caster->pa + M_PI_2) * 3;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->pl_x -= cos(game->caster->pa + M_PI_2) * 3;
		game->pl_y -= sin(game->caster->pa + M_PI_2) * 3;
	}
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	ft_rotate_left(game);
	ft_rotate_right(game);
	ft_move(game);
	raycaster(game);
}

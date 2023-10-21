/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:29:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/19 15:41:12 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->caster->pa -= 0.05;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
	else if (diff > 0)
	{
		if ((diff) > 150)
			diff = 150;
		game->caster->pa -= 0.0006 * diff;
		if (game->caster->pa < 0)
			game->caster->pa += 2 * M_PI;
	}
}

void	ft_rotate_right(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->caster->pa += 0.05;
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
	}
	else if (diff < 0)
	{
		if ((-diff) > 150)
			diff = -150;
		game->caster->pa += 0.0006 * (-diff);
		if (game->caster->pa > 2 * M_PI)
			game->caster->pa -= 2 * M_PI;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:01 by skunert           #+#    #+#             */
/*   Updated: 2023/10/23 16:33:44 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	initialize_vars_to_null(t_map *init)
{
	int	i;

	i = -1;
	init->texture_path_no = NULL;
	init->texture_path_so = NULL;
	init->texture_path_we = NULL;
	init->texture_path_ea = NULL;
	while (++i < 3)
	{
		init->floor_rgb[i] = -1;
		init->ceiling_rgb[i] = -1;
	}
}

int	check_rgb_validity(t_map *init)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (init->floor_rgb[i] == -1 || init->ceiling_rgb[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

int	get_rgb(t_map *init, char *id, char **rgb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) >= 0 && ft_atoi(rgb[i]) <= 255)
		{
			if ((id[0] == 'F' && init->floor_rgb[j] != -1)
				|| (id[0] == 'C' && init->ceiling_rgb[k] != -1))
				return (printf("Error\nduplicate rgb identifier\n"), 1);
			if (id[0] == 'F' && init->floor_rgb[j] == -1)
				init->floor_rgb[j++] = ft_atoi(rgb[i]);
			else if (id[0] == 'C' && init->ceiling_rgb[k] == -1)
				init->ceiling_rgb[k++] = ft_atoi(rgb[i]);
		}
		else
			return (printf("Error\nnot a valid rgb range\n"), 1);
		i++;
	}
	return (0);
}

void	ft_clear_up_other_tex(t_game *g, int i)
{
	if (i == 1)
		mlx_delete_texture(g->floor_tex);
	if (i == 2)
	{
		mlx_delete_texture(g->floor_tex);
		mlx_delete_texture(g->ceiling_tex);
	}
	if (i == 3)
	{
		mlx_delete_texture(g->floor_tex);
		mlx_delete_texture(g->ceiling_tex);
		mlx_delete_texture(g->door_tex);
	}
}

int	ft_get_other_tex(t_game *game)
{
	game->floor_tex = mlx_load_png("./textures/metal.png");
	if (game->floor_tex == NULL)
		return (ft_error_msg("Wall texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->ceiling_tex = mlx_load_png("./textures/night_sky2.png");
	if (game->ceiling_tex == NULL)
		return (ft_clear_up_other_tex(game, 1),
			ft_error_msg("Ceiling texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->door_tex = mlx_load_png("./textures/door.png");
	if (game->door_tex == NULL)
		return (ft_clear_up_other_tex(game, 2),
			ft_error_msg("Door texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->sp->sp_tex = mlx_load_png("./textures/beer.png");
	if (game->sp->sp_tex == NULL)
		return (ft_clear_up_other_tex(game, 3),
			ft_error_msg("Sprite texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:01 by skunert           #+#    #+#             */
/*   Updated: 2023/10/25 16:34:41 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_allocate_helper_structs(t_map *init)
{
	init->game = malloc(sizeof(t_game));
	init->game->drunk = 0;
	init->game->caster = caster_init(init);
	init->game->dl = draw_line_init();
	init->game->ray = ray_init();
	init->game->ds = draw_sprite_init();
	init->game->n_of_coll = check_component('2', init->map);
	init->game->n_of_water = check_component('3', init->map);
	init->game->sp = malloc(sizeof(t_sprite));
	sprite_init(init->game->sp, init);
	init->game->luffy = luffy_init(init->map);
	ft_get_location(init->game, init->map, '2');
	ft_get_location(init->game, init->map, '3');
	init->game->tex = malloc(sizeof(t_tex));
}

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

void	ft_clear_up_other_tex(t_game *g, int i)
{
	if (i == 1)
		mlx_delete_texture(g->tex->floor_tex);
	if (i == 2)
	{
		mlx_delete_texture(g->tex->floor_tex);
		mlx_delete_texture(g->tex->ceiling_tex);
	}
	if (i == 3)
	{
		mlx_delete_texture(g->tex->floor_tex);
		mlx_delete_texture(g->tex->ceiling_tex);
		mlx_delete_texture(g->tex->door_tex);
	}
}

int	ft_get_other_tex(t_game *game)
{
	game->tex->floor_tex = mlx_load_png("./textures/metal.png");
	if (game->tex->floor_tex == NULL)
		return (ft_error_msg("Wall texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->tex->ceiling_tex = mlx_load_png("./textures/night_sky2.png");
	if (game->tex->ceiling_tex == NULL)
		return (ft_clear_up_other_tex(game, 1),
			ft_error_msg("Ceiling texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->tex->door_tex = mlx_load_png("./textures/door.png");
	if (game->tex->door_tex == NULL)
		return (ft_clear_up_other_tex(game, 2),
			ft_error_msg("Door texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->tex->coll_tex = mlx_load_png("./textures/beer.png");
	if (game->tex->coll_tex == NULL)
		return (ft_clear_up_other_tex(game, 3),
			ft_error_msg("Sprite texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	game->tex->water_tex = mlx_load_png("./textures/water.png");
	if (game->tex->water_tex == NULL)
		return (ft_clear_up_other_tex(game, 4),
			ft_error_msg("Sprite texture couldn't be opnened\n"),
			ft_clear_up_tex(game, 4), 1);
	return (0);
}

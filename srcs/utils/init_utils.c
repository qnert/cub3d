/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:01 by skunert           #+#    #+#             */
/*   Updated: 2023/11/03 16:35:47 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_allocate_helper_structs(t_map *init)
{
	init->game = malloc(sizeof(t_game));
	init->game->drunk = 0;
	init->game->game_over = 0;
	init->game->backg_fade = 0;
	init->game->caster = caster_init(init);
	init->game->dl = draw_line_init();
	init->game->ray = ray_init();
	init->game->ds = draw_sprite_init();
	init->game->n_of_coll = check_component('2', init->map);
	init->game->n_of_water = check_component('3', init->map);
	init->game->sp = malloc(sizeof(t_sprite));
	init->game->begin = init->game->sp;
	sprite_init(init->game->sp, init);
	init->game->luffy = luffy_init(init->map);
	if (init->game->luffy == NULL)
		return (init->error = 1, free(NULL));
	init->game->zorro = zorro_init(init->map);
	if (init->game->luffy == NULL)
		return (init->error = 1, free(init->game->luffy));
	ft_get_location(init->game, init->map, '2');
	ft_get_location(init->game, init->map, '3');
	ft_get_location(init->game, init->map, '4');
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

int	ft_get_chest_water_texture(t_game *game)
{
	game->tex->water_tex = mlx_load_png("./textures/water.png");
	if (game->tex->water_tex == NULL)
		return (ft_clear_up_other_tex(game, 4),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	game->tex->chest_tex = mlx_load_png("./textures/chest.png");
	if (game->tex->chest_tex == NULL)
		return (ft_clear_up_other_tex(game, 5),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	return (0);
}

int	ft_get_floor_sky_texture(t_game *game)
{
	if (FLOOR == 1)
	{
		game->tex->floor_tex
			= mlx_load_png("./textures/wooden_wall_no_window.png");
		if (game->tex->floor_tex == NULL)
			return (ft_error_msg("Wall texture couldn't be opened\n"),
				ft_clear_up_wall_tex(game, 4), 3);
	}
	if (SKY == 1)
	{
		game->tex->ceiling_tex = mlx_load_png("./textures/sky_with_clouds.png");
		if (game->tex->ceiling_tex == NULL)
			return (ft_clear_up_other_tex(game, 1),
				ft_error_msg("Ceiling texture couldn't be opened\n"),
				ft_clear_up_wall_tex(game, 4), 3);
	}
	return (0);
}

int	ft_get_other_tex(t_game *game)
{
	if (ft_get_floor_sky_texture(game) == 3)
		return (3);
	game->tex->door_tex = mlx_load_png("./textures/wood_door.png");
	if (game->tex->door_tex == NULL)
		return (ft_clear_up_other_tex(game, 2),
			ft_error_msg("Door texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	game->tex->coll_tex = mlx_load_png("./textures/beer.png");
	if (game->tex->coll_tex == NULL)
		return (ft_clear_up_other_tex(game, 3),
			ft_error_msg("Sprite texture couldn't be opened\n"),
			ft_clear_up_wall_tex(game, 4), 3);
	if (ft_get_chest_water_texture(game) == 3)
		return (3);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:01 by skunert           #+#    #+#             */
/*   Updated: 2023/11/04 15:07:59 by njantsch         ###   ########.fr       */
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

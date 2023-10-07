/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:00 by skunert           #+#    #+#             */
/*   Updated: 2023/10/07 13:26:04 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DIMENS 50

# include "../libft/libs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct rc_cast_directions
{
	double	dir_x;
	double	dir_y;
	double	raydir_x;
	double	raydir_y;
}	t_cast_dir;

typedef struct rc_distances
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
}	t_cast_dist;

typedef struct raycaster
{
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	int			map_x;
	int			map_y;
	char		**map;
	t_cast_dir	*dir;
	t_cast_dist	*dist;
}	t_cast;

typedef struct game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*space;
	int			height;
	int			width;
	t_cast		*caster;
}	t_game;

typedef struct map
{
	int		map_fd;
	char	**map;
	char	*texture_path_no;
	char	*texture_path_ea;
	char	*texture_path_so;
	char	*texture_path_we;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	int		error;
	t_game	*game;
}	t_map;

//game_funcs

//fill_map.c
void	ft_fill_map(t_game *game, char **map);

//game_init.c
int		get_longest_line(char **matrix);
void	game_init(t_map *map);

//get_texture.c
void	get_player_img(t_game *game);
void	get_images(t_game *game);

//game_hooks.c
void	ft_move(t_game *game);
void	ft_hooks(void *param);
void	ft_raycasting_loop(t_cast *caster, int width);
void	raycaster(t_game *game);

//parsing

//check_components.c
bool	complete_component_check(char **map);

//check_file_type.c
void	free_arr(char **arr);
int		ft_check_file_type(char *str);

//map_parser_helper.c
char	**get_and_check_map(int fd);
bool	check_end_walls_curr(char **map);
bool	check_end_walls_next(char **map);

//map_parser.c
char	**get_map(int map_fd);
bool	check_map(char **map);

//utils
int		get_texture_path(t_map *init, char *trmd_line);
int		check_line(t_map *init, char *line);
int		get_input(t_map *init);
t_map	*strct_init(char *file_path);
int		check_rgb(t_map *init, char *trmd_line);
int		get_rgb(t_map *init, char *id, char **rgb);
int		check_rgb_validity(t_map *init);
void	initialize_vars_to_null(t_map *init);

//parsing_utils.c
bool	is_whitespace(char c);
int		ft_matrixlen(char **matrix);
bool	is_component(char c);
bool	is_valid_border(char c);
void	ft_error_msg(char *str);

//texture_utils.c
void	set_pixels_img(mlx_image_t *img, int max_x, int max_y, u_int32_t c);

//casting_utils.c
t_cast	*caster_init(t_map *init);


#endif

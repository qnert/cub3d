/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:00 by skunert           #+#    #+#             */
/*   Updated: 2023/10/17 23:23:42 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DIMENS 128
# define DGREE 0.0174533

# include "../libft/libs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct sprite
{
	mlx_texture_t	*sp_tex;
	int	type; //collectible, enemy
	int	state; //on, off
	int	x;
	int	y;
	int	z;
}	t_sprite;

typedef struct draw_line
{
	double		tx;
	double		ty;
	double		dy;
	double		fix_ra;
	int			pixel;
	int			begin_x;
	int			begin_y;
	int			end_x;
	int			end_y;
	int			color;
	int			x_off;
}	t_draw_line;

typedef struct ray
{
	int		rays;
	int		n_of_rays;
	int		depoffield;
	int		player_x;
	int		player_y;
	double	ray_x;
	double	ray_y;
	double	ray_a;
	double	x_o;
	double	y_o;
	double	dist_h;
	double	dist_v;
	double	ver_x;
	double	ver_y;
	double	hor_x;
	double	hor_y;
	double	final_d;
	double	a_tan;
	double	n_tan;
	double	shade;
	double	tex_x;
	double	tex_y;
	double	ty_step;
	double	ty_off;
}	t_ray;

typedef struct caster
{
	double		pd_x;
	double		pd_y;
	double		pd_x_strafe;
	double		pd_y_strafe;
	double		pa;
	double		ca;
	int			line_hight;
	int			line_offset;
	int			x_off;
	int			y_off;
	int			x_off_strafe;
	int			y_off_strafe;
	int			map_x;
	int			map_y;
	int			map_p;
	char		**map;
}	t_cast;

typedef struct game
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*line;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*door_tex;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*ceiling_tex;
	int				height;
	int				width;
	int				dis_w;
	int				dis_h;
	double			pl_x;
	double			pl_y;
	t_cast			*caster;
	t_draw_line		*dl;
	t_ray			*ray;
	t_sprite		*sp;
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
void		ft_fill_map(t_game *game, char **map);
void		ft_get_location(t_game *game, char **map);

//game_init.c
int			get_longest_line(char **matrix);
void		game_init(t_map *map);

//get_texture.c
void		get_player_img(t_game *game);
void		get_images(t_game *game);

//game_hooks.c
void		ft_move(t_game *game);
void		ft_hooks(void *param);
void		raycaster(t_game *game);
void		ft_rotate_left(t_game *game);
void		ft_rotate_right(t_game *game);

//parsing

//check_components.c
int			check_component(char c, char **map);
bool		complete_component_check(char **map);

//check_file_type.c
void		free_arr(char **arr);
int			ft_check_file_type(char *str);

//map_parser_helper.c
char		**get_and_check_map(int fd);
bool		check_end_walls_curr(char **map);
bool		check_end_walls_next(char **map);

//map_parser.c
char		**get_map(int map_fd);
bool		check_map(char **map);

//utils
//init.c
int			get_texture_path(t_map *init, char *trmd_line);
int			check_line(t_map *init, char *line);
int			get_input(t_map *init);
t_map		*strct_init(char *file_path);
int			check_rgb(t_map *init, char *trmd_line);

//init_utils.c
void		initialize_vars_to_null(t_map *init);
int			check_rgb_validity(t_map *init);
int			get_rgb(t_map *init, char *id, char **rgb);

//parsing_utils.c
bool		is_whitespace(char c);
int			ft_matrixlen(char **matrix);
bool		is_component(char c);
bool		is_valid_border(char c);
void		ft_error_msg(char *str);

//render_utils.c
void		ft_draw_walls(t_game *g);
void		ft_set_values_floor_ceiling(t_game *g);
void		ft_set_values_for_rendering(t_game *g);
void		ft_set_values_and_render_funcs(t_game *g);

//texture_utils.c
void		set_pixels_img(mlx_image_t *img, int max_x, int max_y, u_int32_t c);
void		draw_sky(t_game *g);
void		scale_texture(t_game *g, int x, int y, int scale);

//casting_utils.c
t_cast		*caster_init(t_map *init);
int			ft_abs(int num);
t_draw_line	*draw_line_init(void);
t_ray		*ray_init(void);
int			rad_to_degree(double rad);
t_sprite	*sprite_init(void);

//hook_utils.c
void		ft_move_up_down(t_game *g);
void		ft_move_left_right(t_game *g);
void		ft_check_door(t_game *g);

//draw_line.c
void		ft_draw_line_3D(t_game *game);

//caster.c
void		set_limit(t_game *g);
double		ft_distance(t_game *g, double bx, double by);
void		set_cosine_and_values(t_game *g);

// horizontal.c
void		check_horizontal_line(t_game *g);

// vertical.c
void		check_vertical_line(t_game *g);
void		replace_img(t_game *g);
#endif

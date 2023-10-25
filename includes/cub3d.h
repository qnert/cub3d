/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:00 by skunert           #+#    #+#             */
/*   Updated: 2023/10/25 16:22:01 by njantsch         ###   ########.fr       */
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

// type 2 == beer
// type 3 == water
typedef struct sprite
{
	int				type;
	int				state;
	int				x;
	int				y;
	int				z;
	struct sprite	*next;
}	t_sprite;

typedef struct draw_sprite
{
	double		sx;
	double		sy;
	double		sz;
	double		t_x;
	double		t_y;
	double		cosine;
	double		sine;
	double		rot_a;
	double		rot_b;
}	t_draw_sprite;

typedef struct draw_line
{
	double		tx;
	double		ty;
	double		dy;
	double		fix_ra;
	int			delta_x;
	int			delta_y;
	int			direction_x;
	int			direction_y;
	int			error;
	int			two_times_error;
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

typedef struct textures
{
	mlx_texture_t	*wall_north_tex;
	mlx_texture_t	*wall_south_tex;
	mlx_texture_t	*wall_west_tex;
	mlx_texture_t	*wall_east_tex;
	mlx_texture_t	*door_tex;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*ceiling_tex;
	mlx_texture_t	*coll_tex;
	mlx_texture_t	*water_tex;
	mlx_texture_t	*enemy_tex;
}	t_tex;

typedef struct game
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*line;
	mlx_image_t		*minimap;
	int				height;
	int				width;
	int				dis_w;
	int				dis_h;
	double			pl_x;
	double			pl_y;
	int				n_of_coll;
	int				n_of_water;
	double			drunk;
	t_cast			*caster;
	t_draw_line		*dl;
	t_ray			*ray;
	t_sprite		*sp;
	t_draw_sprite	*ds;
	t_tex			*tex;
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
void			ft_clear_up_tex(t_game *g, int i);
int				ft_fill_map(t_game *game, t_map *m);

//game_init.c
int				get_longest_line(char **matrix);
int				game_init(t_map *map);

//get_texture.c
void			get_player_img(t_game *game);
void			get_images(t_game *game);

//game_hooks.c
void			ft_move(t_game *game);
void			ft_hooks(void *param);
void			raycaster(t_game *game);
void			ft_rotate_left(t_game *game, int diff);
void			ft_rotate_right(t_game *game, int diff);
void			ft_wall_offset_set(t_game *g);

//parsing

//check_components.c
int				check_component(char c, char **map);
bool			complete_component_check(char **map);

//check_file_type.c
void			free_arr(char **arr);
int				ft_check_file_type(char *str);

//map_parser_helper.c
char			**get_and_check_map(int fd);
bool			check_end_walls_curr(char **map);
bool			check_end_walls_next(char **map);

//map_parser.c
char			**get_map(int map_fd);
bool			check_map(char **map);

//utils
//init.c
int				get_texture_path(t_map *init, char *trmd_line);
int				check_line(t_map *init, char *line);
int				get_input(t_map *init);
t_map			*strct_init(char *file_path);
int				check_rgb(t_map *init, char *trmd_line);

//init_utils.c
void			initialize_vars_to_null(t_map *init);
int				check_rgb_validity(t_map *init);
int				get_rgb(t_map *init, char *id, char **rgb);
int				ft_get_other_tex(t_game *game);

//minimap.c
void			ft_fill_minimap(t_game *g);
void			draw_minimap(t_game *g);
void			ft_fill_miniplayer(t_game *g, int x, int y);

//mini_map_utils.c
void			ft_fill_minimap_walls(t_game *g);

//parsing_utils.c
bool			is_whitespace(char c);
int				ft_matrixlen(char **matrix);
bool			is_component(char c);
bool			is_valid_border(char c);
void			ft_error_msg(char *str);

//draw_utils.c
void			ft_draw_sprites(t_game *g);
void			ft_draw_walls(t_game *g);
void			ft_draw_floor_ceiling(t_game *g, int i);
void			draw_sky(t_game *g);

//render_utils.c
void			ft_set_values_floor_ceiling(t_game *g);
void			ft_set_values_for_rendering(t_game *g);
void			ft_set_values_and_render_funcs(t_game *g);

//texture_utils.c
uint32_t		get_right_wall_color(t_game *g);
void			set_pixels_img(mlx_image_t *img, int max_x,
					int max_y, u_int32_t c);
void			scale_texture(t_game *g, int x, int y, int scale);

//math_utils.c
void			ft_check_right_distance(t_game *g);
int				ft_abs(int num);
int				rad_to_degree(double rad);

//casting_utils.c
t_cast			*caster_init(t_map *init);
t_draw_line		*draw_line_init(void);
t_ray			*ray_init(void);
t_draw_sprite	*draw_sprite_init(void);

//hook_utils.c
void			ft_move_up_down(t_game *g);
void			ft_move_left_right(t_game *g);
void			ft_check_door(t_game *g);
bool			ft_check_collision(char c);

//draw_line.c
void			ft_draw_line(t_game *game, int i);

//caster.c
void			set_limit(t_game *g);
double			ft_distance(t_game *g, double bx, double by);
void			set_cosine_and_values(t_game *g);

// horizontal.c
void			check_horizontal_line(t_game *g);

// vertical.c
void			check_vertical_line(t_game *g);
void			replace_img(t_game *g);

//sprites.c
void			ft_set_values_sprites(t_game *g);

//sprite_utils.c
void			sprite_init(t_sprite *sp, t_map *m);
void			ft_get_location(t_game *game, char **map, char c);
void			free_lst_sprites(t_sprite *lst);

#endif

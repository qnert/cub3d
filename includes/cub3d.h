/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:00 by skunert           #+#    #+#             */
/*   Updated: 2023/11/05 15:30:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DIMENS 128
# define DGREE 0.0174533

// If define is set to 1, texture will be used
// and/or the bonus part
// If not defined, RGB in map will be used
# ifndef SKY
#  define SKY 0
# endif
# ifndef FLOOR
#  define FLOOR 0
# endif
# ifndef BONUS
#  define BONUS 0
# endif

# include "../libft/libs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct zorro
{
	mlx_texture_t	**animation;
	int				i;
	int				check;
	double			x;
	double			y;
	int				z;
}	t_zorro;

typedef struct luffy
{
	mlx_texture_t	**animation;
	int				i;
	int				check;
	int				x;
	int				y;
	int				z;
}	t_luffy;

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
	mlx_texture_t	*chest_tex;
}	t_tex;

typedef struct game
{
	mlx_t			*mlx;
	mlx_image_t		*line;
	mlx_image_t		*minimap;
	mlx_image_t		*background;
	mlx_image_t		*floor;
	mlx_image_t		*ceiling;
	mlx_image_t		*minimap_rc;
	int				height;
	int				width;
	int				dis_w;
	int				dis_h;
	double			pl_x;
	double			pl_y;
	int				n_of_coll;
	int				n_of_water;
	double			drunk;
	int				game_over;
	int				backg_fade;
	t_cast			*caster;
	t_draw_line		*dl;
	t_ray			*ray;
	t_sprite		*begin;
	t_sprite		*sp;
	t_draw_sprite	*ds;
	t_tex			*tex;
	t_luffy			*luffy;
	t_zorro			*zorro;
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
	int		replay_check;
	t_game	*game;
}	t_map;

// directory cleanup
//del_tex.c
void			ft_clear_up_wall_tex(t_game *g, int i);
void			ft_clear_up_other_tex(t_game *g, int i);

//free.c
void			ft_free_luffy_zorro(t_map *map);
void			ft_terminate_struct_helper(t_map *map);
void			ft_terminate_struct(t_map *map);

// directory game_funcs

//fill_map.c
void			ft_fill_player(t_game *game, char **map);
void			change_wall_tex_size(t_game *game, int tex);
bool			check_wall_tex_size(t_game *game);
int				ft_fill_map(t_game *game, t_map *m);

//game_hooks.c
void			check_game_exit(t_game *game);
void			ft_wall_offset_set(t_game *g);
void			check_game_over(t_game *game);
void			ft_hooks(void *param);

//game_init.c
int				get_longest_line(char **matrix);
void			ft_game_begin(t_game *game, t_map *m);
void			game_init(t_map *map);

// directory graphics
//get_texture.c
int				ft_get_chest_water_texture(t_game *game);
int				ft_get_floor_sky_texture(t_game *game);
int				ft_get_other_tex(t_game *game);

//set_sky_floor_color.c
uint32_t		get_rgb_in_hex(int r, int g, int b);
void			draw_sky_with_color(t_game *game, t_map *m);
void			draw_floor_with_color(t_game *game, t_map *m);
void			get_images(t_game *game, t_map *m);

//texture_utils.c
uint32_t		get_right_north_south_color(t_game *g);
uint32_t		get_right_west_east_color(t_game *g);
uint32_t		get_right_wall_color(t_game *g);
void			set_pixels_img(mlx_image_t *img, int max_x,
					int max_y, u_int32_t c);
void			scale_texture(t_game *g, int x, int y, int scale);

// directory minimap
//draw_line.c
void			ft_dl_assign_values(t_game *game);
void			ft_draw_line(t_game *game, int i);

//minimap.c
void			draw_minimap(t_game *g);
void			ft_fill_miniplayer(t_game *g, int x, int y);
int				check_free_char(char c);
uint32_t		ft_check_color(t_game *g, double x, double y);
void			ft_fill_minimap(t_game *g);

// directory parsing
// check_components.c
int				check_component(char c, char **map);
char			check_player_pos(char **map);
bool			check_invalid_component(char **map);
bool			complete_component_check(char **map);

//file_type.c
void			free_arr(char **arr);
int				ft_check_file_type(char *str);

//map_parser_helper.c
char			**get_and_check_map(int fd);
bool			check_end_walls_curr(char **map);
bool			check_end_walls_next(char **map);
char			*check_map_nl(char *line, int map_fd);

//map_parser.c
bool			check_side_line(char **map, int index);
bool			check_middle_lines(char **map);
bool			check_whitespace_border(char **map);
bool			check_map(char **map);
char			**get_map(int map_fd);

//rgb_parsing.c
int				check_rgb_validity(t_map *init);
int				get_rgb(t_map *init, char *id, char **rgb);
int				check_rgb_loop(char **rgb, char *trmd, int i, int j);
char			*trim_spaces(char *line);
int				check_rgb(t_map *init, char *line);

//texture_path_parsing.c
int				get_input(t_map *init);
bool			check_identifier(char *line, int check);
int				check_line(t_map *init, char *line);
int				get_texture_path(t_map *init, char *trmd_line);

// directory player_funcs
//player_movement.c
void			ft_move_up_down(t_game *g);
void			ft_move_left_right(t_game *g);
void			ft_move(t_game *game);

//player_rotation.c
void			ft_rotate_left(t_game *game, int diff);
void			ft_rotate_right(t_game *game, int diff);

// directory raycaster
//caster.c
void			replace_img(t_game *g);
void			set_limit(t_game *g);
double			ft_distance(t_game *g, double bx, double by);
void			set_cosine_and_values(t_game *g);
void			raycaster(t_game *g);

//horizontal.c
void			assign_variables_horizontal(t_game *g);
void			check_horizontal_wall(t_game *g);
void			check_horizontal_line(t_game *g);

//render_utils.c
void			ft_set_values_floor_ceiling(t_game *g);
void			ft_set_values_for_rendering(t_game *g);
void			ft_set_values_and_render_funcs(t_game *g);

//vertical.c
void			assign_variables_vertical(t_game *g);
void			check_vertical_wall(t_game *g);
void			check_vertical_line(t_game *g);

// directory sprites
//draw_sprites.c
void			ft_draw_beer(t_game *g, int x, int y, int scale);
void			ft_draw_water(t_game *g, int x, int y, int scale);
void			ft_draw_chest(t_game *g, int x, int y, int scale);
void			ft_draw_sprites(t_game *g);

//luffy_set_values.c
void			ft_get_luffy_colors_and_draw(t_game *g, int x, int y);
int				ft_draw_luffy_tex_loop(t_game *g, int x, int scale);
void			ft_draw_luffy_tex(t_game *g, int x, int scale);
void			ft_draw_luffy(t_game *g);
void			ft_set_values_luffy(t_game *g);

//luffy_utils.c
void			free_prior_pngs(mlx_texture_t **animation, int n);
mlx_texture_t	**load_all_pngs(int i);
void			ft_get_location_luffy(char **map, t_luffy *luf);
t_luffy			*luffy_init(char **map);

//sprite_utils.c
void			free_lst_sprites(t_sprite *lst);
void			ft_get_location(t_game *game, char **map, char c);
t_sprite		*new_lst_node_sprite(t_sprite *curr,
					t_sprite *new_node, int type);
void			sprite_init(t_sprite *start, t_map *m);

//sprites.c
bool			ft_check_walls_sprite(t_game *g, double x, double y);
void			increment_drunkness(t_game *g);
void			decrement_drunkness(t_game *g);
void			check_sprite_type_for_draw(t_game *g, int x, int y, int scale);
void			ft_set_values_sprites(t_game *g);

//zorro_set_values.c
void			ft_get_zorro_colors_and_draw(t_game *g, int x, int y);
int				ft_draw_zorro_tex_loop(t_game *g, int x, int scale);
void			ft_draw_zorro_tex(t_game *g, int x, int scale);
void			ft_draw_zorro(t_game *g);
void			ft_set_values_zorro(t_game *g);

//zorro_utils.c
void			enemy_follow(t_game *game);
// static mlx_texture_t	**load_all_pngs_zorro(int i);
void			ft_get_location_zorro(char **map, t_zorro *zorr);
t_zorro			*zorro_init(char **map);

// directory utils
//draw_utils.c
void			ft_draw_walls(t_game *g);
void			ft_draw_floor_ceiling(t_game *g, int i);
void			draw_sky(t_game *g);

//hook_utils.c
bool			ft_check_collision(char c);
void			ft_close_doors(t_game *g);
void			ft_check_door(t_game *g);

//init_utils.c
void			ft_allocate_helper_structs(t_map *init);
void			initialize_vars_to_null(t_map *init);

//init.c
t_map			*strct_init(char *file_path);
t_ray			*ray_init(void);
t_draw_line		*draw_line_init(void);
t_draw_sprite	*draw_sprite_init(void);
t_cast			*caster_init(t_map *init);

//math_utils.c
void			ft_check_right_distance(t_game *g);
int				rad_to_degree(double rad);
int				ft_abs(int num);

//parsing_utils.c
bool			is_whitespace(char c);
int				ft_matrixlen(char **matrix);
bool			is_component(char c);
bool			is_valid_border(char c);
void			ft_error_msg(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:19:00 by skunert           #+#    #+#             */
/*   Updated: 2023/10/05 12:01:29 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libs.h"
// #include "./MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

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
}	t_map;

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

//parsing_utils.c
bool	is_whitespace(char c);
int		ft_matrixlen(char **matrix);
bool	is_component(char c);
bool	is_valid_border(char c);
void	ft_error_msg(char *str);

#endif

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
USER = $(shell whoami)
MLXFLAGS = -Iinclude -lglfw
NAME = cub3D
BONUS_NAME = cub3d

SRCS = main.c ./srcs/parsing/file_type.c ./srcs/utils/init.c ./srcs/utils/parsing_utils.c ./srcs/parsing/check_components.c \
		./srcs/parsing/map_parser.c ./srcs/parsing/map_parser_helper.c ./srcs/game_funcs/game_init.c ./srcs/game_funcs/game_hooks.c \
		./srcs/graphics/get_textures.c ./srcs/game_funcs/fill_map.c ./srcs/graphics/texture_utils.c ./srcs/minimap/draw_line.c \
		./srcs/raycaster/caster.c ./srcs/raycaster/horizontal.c ./srcs/raycaster/vertical.c ./srcs/utils/init_utils.c \
		./srcs/utils/hook_utils.c ./srcs/raycaster/render_utils.c ./srcs/minimap/minimap.c ./srcs/player_funcs/player_movement.c \
		./srcs/player_funcs/player_rotation.c ./srcs/utils/draw_utils.c ./srcs/utils/math_utils.c \
		./srcs/sprites/sprites.c ./srcs/sprites/sprite_utils.c ./srcs/sprites/luffy_utils.c ./srcs/sprites/luffy_set_values.c \
		./srcs/parsing/rgb_parsing.c ./srcs/sprites/zorro_utils.c ./srcs/sprites/zorro_set_values.c ./srcs/sprites/draw_sprites.c \
		./srcs/cleanup/del_tex.c ./srcs/cleanup/free.c ./srcs/parsing/texture_path_parsing.c ./srcs/graphics/set_sky_floor_color.c

OBJS = $(SRCS:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@cd libft && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf MLX42
	@cd libft && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: CFLAGS += -D SKY=1 -D FLOOR=1 -D BONUS=1
bonus: MLX42 $(BONUS_NAME)
$(BONUS_NAME): $(OBJS)
	@cd libft && make
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS) ./libft/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

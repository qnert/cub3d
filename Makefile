CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
USER = $(shell whoami)
MLXFLAGS = -Iinclude -lglfw
NAME = cub3D

SRCS = main.c ./srcs/parsing/file_type.c ./srcs/utils/init.c ./srcs/utils/parsing_utils.c ./srcs/parsing/check_components.c \
		./srcs/parsing/map_parser.c ./srcs/parsing/map_parser_helper.c ./srcs/game_funcs/game_init.c ./srcs/game_funcs/game_hooks.c \
		./srcs/game_funcs/get_texture.c ./srcs/game_funcs/fill_map.c ./srcs/utils/casting_utils.c \
		./srcs/utils/texture_utils.c ./srcs/game_funcs/draw_line.c ./srcs/raycaster/caster.c ./srcs/raycaster/horizontal.c \
		./srcs/raycaster/vertical.c ./srcs/utils/init_utils.c ./srcs/utils/hook_utils.c ./srcs/utils/render_utils.c \
		./srcs/raycaster/minimap.c ./srcs/player_funcs/player_movement.c ./srcs/player_funcs/player_rotation.c ./srcs/utils/mini_map_utils.c \
		./srcs/utils/draw_utils.c ./srcs/utils/math_utils.c ./srcs/sprites/sprites.c ./srcs/sprites/sprite_utils.c \
		./srcs/sprites/luffy_utils.c ./srcs/sprites/luffy_set_values.c ./srcs/utils/rgb_utils.c ./srcs/sprites/zorro_utils.c \
		./srcs/sprites/zorro_set_values.c ./srcs/sprites/draw_sprites.c

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

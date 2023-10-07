CC = cc
CFLAGS = -Wall -Wextra -Werror
USER = $(shell whoami)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
NAME = cub3D

SRCS = main.c ./srcs/parsing/file_type.c ./srcs/utils/init.c ./srcs/utils/parsing_utils.c ./srcs/parsing/check_components.c \
		./srcs/parsing/map_parser.c ./srcs/parsing/map_parser_helper.c ./srcs/game_funcs/game_init.c ./srcs/game_funcs/game_hooks.c \
		./srcs/game_funcs/get_texture.c ./srcs/game_funcs/fill_map.c ./srcs/raycaster/caster.c ./srcs/utils/casting_utils.c \
    ./srcs/utils/texture_utils.c

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

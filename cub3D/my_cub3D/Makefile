NAME 		=	cub3D

SRCS 		=	cub3d.c \
				srcs/exit.c \
				srcs/parse_hub.c \
				srcs/parse_resolution.c \
				srcs/parse_texture_color.c \
				srcs/parse_map.c \
				srcs/parse_map_player.c \
				srcs/parse_utils.c \
				srcs/init_hub.c \
				srcs/init_xpm.c \
				srcs/control_camera.c \
				srcs/control_player.c \
				srcs/config_key.c \
				srcs/raycasting_a.c \
				srcs/raycasting_b.c \
				srcs/sprite.c \
				srcs/draw_sprite.c \
				srcs/texture.c \
				srcs/image.c \
				srcs/screenshot.c \

OBJS		=	${SRCS:%.c=%.o}

FLAGS		=	-Wall -Wextra -Werror

LEAKS		=	-g3 -fsanitize=address -fsanitize=undefined -std=c99

MLX			=	-Llibs/minilibx -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	@$(MAKE) re -C ./Libft
	@$(MAKE) re -C ./mlx
	@gcc $(FLAGS) $(OBJS) -I $(MLX) ./Libft/libft.a -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./mlx
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME)
	$(MAKE) -C ./Libft fclean
	rm -rf screenshot.bmp

re : fclean	all

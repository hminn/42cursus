NAME 		=	cub3D

LIBFT = ./Libft/libft.a

CC = gcc
INCS = -I./ -I./Libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft

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

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) clean -C ./mlx
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf screenshot.bmp

re: fclean all

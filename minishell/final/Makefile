NAME	=	minishell

SRCS	= 	srcs/main.c \
			srcs/exec_redirect.c \
			srcs/run_cd.c \
			srcs/run_cmds.c \
			srcs/run_env.c \
			srcs/run_etc.c \
			srcs/run_exit.c \
			srcs/run_export.c \
			srcs/run_pipe.c \
			srcs/run_redirect.c \
			srcs/run_unset.c \
			srcs/func_check.c \
			srcs/func_env.c \
			srcs/func_etc.c \
			srcs/func_export.c \
			srcs/func_parse.c \
			srcs/func_redirect.c \
			srcs/get_argv.c \
			srcs/handle_signal.c \
			srcs/parse_line.c \
			srcs/print_prompt.c \

LEAKS	=	-g3 -fsanitize=address

LIBS	=	-L./libft -lft

LIBFT	=	libft.a

HEADER	=	-I./includes

FLAG	= 	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(LIBFT)
	$(CC) $(SRCS) $(LIBS) $(HEADER) $(FLAG) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

clean	:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean	:
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re		: fclean all

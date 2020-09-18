SRCS =  ft_printf.c \
		src/ft_treatment.c \
		src/ft_treat_width.c \
		src/ft_u_itoa.c \
		src/ft_ull_base.c \
		src/ft_utils.c \
		src/ft_treat_string.c \
		src/ft_treat_char.c \
		src/ft_treat_pointer.c \
		src/ft_treat_int.c \
		src/ft_treat_uint.c \
		src/ft_treat_percent.c \
		src/ft_treat_hexa.c \
		src/ft_treat_flags.c

LIBFT = libft

LIBFT_A = libft.a

INCLUDES = ./includes

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

ARRC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I$(INCLUDES)

$(NAME):	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_A) $(NAME)
		$(ARRC) $(NAME) $(OBJS)

all :		$(NAME)

bonus :		$(NAME)
		ar rc $(NAME)

clean :
			$(RM) -f $(OBJS) $(OBJS_B)
			make clean -C $(LIBFT)

fclean :	clean
			$(RM) $(NAME) $(bonus)
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY : all bonus clean fclean re .c.o
NAME = ../../push_swap

SRCS =	./main.c \
		./sort.c \
		../public/stack.c \
		../public/stack2.c \
		../public/instructions.c \
		../public/instructions2.c \
		../public/utils.c \
		../public/quick_sort.c \
		./optimize.c

OBJS	=	$(SRCS:%.c=%.o)

LIBS	=	-L../../libft -lft

LIBFT	=	libft.a

HEADER	=	../../includes

CC		=	gcc

RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(OBJS) $(HEADER) $(LIBFT)
	$(CC) $(SRCS) $(LIBS) -I $(HEADER) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ../../libft

clean	:
	$(MAKE) -C ../../libft clean
	rm -rf $(OBJS)

fclean	:
	$(MAKE) -C ../../libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
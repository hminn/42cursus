NAME = philo_one
CC = gcc
SRCS =	main.c \
		parsing.c \
		init.c \
		philo.c \
		print.c \
		monitoring.c \
		utils.c
C_FLAG = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
LIBS = -lpthread

.c.o:
	${CC} ${C_FLAG} -c $< -o ${<:.c=.o} -I Includes/

${NAME}: ${OBJS}
	$(CC) $(C_FLAG) $(OBJS) -o $(NAME) ${LIBS}

all: ${NAME}

clean :
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o
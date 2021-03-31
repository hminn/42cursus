MAKE1					=	./libft
MAKE2					=	./srcs/checker
MAKE3					=	./srcs/push_swap

# TEST					=	./Mktest

CLEAN					=	make clean -C
FCLEAN					=	make fclean -C

.PHONY					:	clean fclean re

all						:
							make -C $(MAKE1)
							make -C $(MAKE2)
							make -C $(MAKE3)

clean					:
							$(CLEAN) $(MAKE1)
							$(CLEAN) $(MAKE2)
							$(CLEAN) $(MAKE3)
							# $(CLEAN) $(TEST)

fclean					:	clean
							$(FCLEAN) $(MAKE1)
							$(FCLEAN) $(MAKE2)
							$(FCLEAN) $(MAKE3)
							# $(FCLEAN) $(TEST)

# test					:	all
# 							make -C $(TEST)

re						:	fclean all
CC	=	gcc
NAME	=	conv_nbr
SRC	=	$(NAME).c
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-W -Wall -Wextra -Werror -ggdb3
RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean:		clean
	$(RM) $(OBJ)

re:		fclean all

.PHONY:		all clean fclean re

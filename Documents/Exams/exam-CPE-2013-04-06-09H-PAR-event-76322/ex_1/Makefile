CC 	= gcc
SRC 	= conv_nbr.c
OBJ	= $(SRC:.c=.o)
NAME 	= conv_nbr

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(SRC) -ggdb3

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
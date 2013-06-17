CC 	= gcc
SRC 	= my_id.c
OBJ	= $(SRC:.c=.o)
NAME 	= my_id

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(SRC) -ggdb3

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
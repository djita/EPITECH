CC	=	gcc

NAME	=	union

SRCS	=	union.c

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-ansi -pedantic -W -Wall -Wextra -ggdb3

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(FLAGS)

clean:		
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
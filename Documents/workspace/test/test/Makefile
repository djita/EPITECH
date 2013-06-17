CC	=	gcc
RM	=	rm -f
NAME	=	comlink

SRCS	=	comlink.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-ansi -pedantic -W -Wall -Wextra -Werror -ggdb3
LFLAGS	=	

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean:		clean
	$(RM) $(OBJS)

re:		fclean all

.PHONY:		all clean fclean re

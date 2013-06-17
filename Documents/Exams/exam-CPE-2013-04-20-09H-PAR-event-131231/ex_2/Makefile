CC	= 	gcc
NAME	= 	wdmatch
SRCS	= 	wdmatch.c
OBJS	= 	$(SRCS:.c=.o)
CFLAGS	=	-ansi -pedantic -W -Wall -Wextra -Werror -ggdb3
RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CLAGS)

clean:
	$(RM) $(NAME)

fclean:		clean
	$(RM) $(OBJS)

re:		fclean all

.PHONY:		all re clean fclean
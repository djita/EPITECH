CC	= 	gcc
NAME	= 	sopipa
SRCS	= 	sopipa.c
OBJS	= 	$(SRCS:.c=.o)
CFLAGS	=	-ggdb3
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
CC	=	gcc
RM	=	rm -f
NAME	=	common_str
SRCS	=	common_str.c
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-ggdb3

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:		
	$(RM) $(NAME)

fclean:		clean
	$(RM) $(OBJS)

re:		fclean all

.PHONY:		all clean fclean re
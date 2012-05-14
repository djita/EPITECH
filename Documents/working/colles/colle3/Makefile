##
## Makefile for carre in /home/guillo_e//Documents/working/colles/colle3
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon Apr 30 19:18:46 2012 lyoma guillou
## Last update Mon Apr 30 22:16:29 2012 lyoma guillou
##

CC	=	gcc

NAME	=	carre

SRCS	=	src/key.c		\
		src/my_strcmp.c		\
		src/my_getnbr.c		\
		src/char_type.c		\
		src/draw_line.c 	\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I./include -I/usr/include/

LIB	=	-L /usr/X11/lib -lmlx -lXext -lX11

LDFLAGS =

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all re clean fclean
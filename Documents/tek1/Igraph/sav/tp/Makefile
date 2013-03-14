##
## Makefile for igraph in /home/guillo_e//working/test/igraph
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Oct 27 10:36:31 2011 lyoma guillou
## Last update Wed Jan 11 11:52:19 2012 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.

NAME 	= 	wolf3d

LIB 	= 	-L /usr/X11/lib -lmlx -lXext -lX11

SRCS	=	main.c \
		arrow_keys.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: fclean all

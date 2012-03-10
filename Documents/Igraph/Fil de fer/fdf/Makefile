##
## Makefile for igraph in /home/guillo_e//working/test/igraph
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Oct 27 10:36:31 2011 lyoma guillou
## Last update Sun Dec 11 19:55:20 2011 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.

NAME 	= 	fdf

LIB 	= 	-L /usr/X11/lib -lmlx -lXext -lX11

SRCS	=	main.c \
		get_next_line.c \
		fdf_funcs.c \
		grid_funcs.c \
		get_funcs.c \
		map_recover.c \
		my_str_to_wordtab.c \
		put_funcs.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: fclean all

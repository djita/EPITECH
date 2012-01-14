##
## Makefile for myls in /home/guillo_e//working/unix
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Fri Nov 25 18:13:52 2011 lyoma guillou
## Last update Sun Dec  4 06:35:15 2011 lyoma guillou
##

CC	=	gcc

RM	=	rm -f

CFLAGS +=	-Wextra -Wall -Werror
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.
CFLAGS +=	-D_BSD_SOURCE -D_X_OPEN_SOURCE=500

NAME	=	my_ls

SRCS 	= 	main.c \
		my_ls.c \
		opt_check.c \
		file_check.c \
		put_funcs.c \
		str_funcs.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

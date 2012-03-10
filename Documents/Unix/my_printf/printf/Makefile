##
## Makefile for Makefile in /home/guillo_e//working/test/printf
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Wed Nov  9 20:54:25 2011 lyoma guillou
## Last update Sat Nov 19 18:00:27 2011 lyoma guillou
##

CC 	=	clang

RM 	=	rm -f

CFLAGS +=	-Wextra -Wall -Werror
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.
CFLAGS +=	-Wno-long-long

LDFLAGS =

NAME 	= 	my_printf

SRCS 	= 	my_putchar.c \
		my_putstr.c \
		check_funcs.c \
		putnbr_funcs.c \
		my_printf.c \
		main.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

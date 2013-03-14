##
## Makefile for minishell in /home/guillo_e//working/unix/minishell
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Dec 15 19:03:35 2011 lyoma guillou
## Last update Sun Jan  8 20:04:05 2012 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.
CFLAGS +=	-D_XOPEN_SOURCE=500

LDFLAGS =

NAME 	= 	push_swap

SRCS 	= 	main.c \
		list_funcs.c \
		get_funcs.c \
		put_funcs.c \
		swap_push_op.c \
		rotate.c \
		sort_func.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

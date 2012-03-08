##
## Makefile for minishell in /home/guillo_e//working/unix/minishell
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Dec 15 19:03:35 2011 lyoma guillou
## Last update Fri Mar  2 19:00:05 2012 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-Iinclude -I.
#CFLAGS +=	-D_XOPEN_SOURCE=500
CFLAGS +=	-ggdb3

NAME 	= 	mysh

SRCS 	= 	src/main.c \
		src/my_str_to_wordtab.c \
		src/get_funcs.c \
		src/mem_funcs.c \
		src/str_funcs.c \
		src/put_funcs.c \
		src/tab_funcs.c \
		src/x_funcs.c \
		src/envp.c \
		src/command.c \
		src/signal.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

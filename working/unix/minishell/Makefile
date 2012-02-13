##
## Makefile for minishell in /home/guillo_e//working/unix/minishell
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Dec 15 19:03:35 2011 lyoma guillou
## Last update Fri Feb 10 17:51:18 2012 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.
CFLAGS +=	-D_XOPEN_SOURCE=500
CFLAGS +=	-ggdb3

LDFLAGS =

NAME 	= 	mysh

SRCS 	= 	src/main.c \
		src/my_str_to_wordtab.c \
		src/mem_funcs.c \
		src/str_funcs.c \
		src/str_utils.c \
		src/tab_funcs.c \
		src/envp.c \
		src/command.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

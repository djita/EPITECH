##
## Makefile for minishell in /home/guillo_e//working/unix/minishell
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Dec 15 19:03:35 2011 lyoma guillou
## Last update Tue Jan 31 16:27:03 2012 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.
CFLAGS +=	-D_XOPEN_SOURCE=500

LDFLAGS =

NAME 	= 	mysh

SRCS 	= 	main.c \
		my_str_to_wordtab.c \
		mem_funcs.c \
		str_funcs.c \
		str_utils.c \
		tab_funcs.c \
		envp.c \
		command.c

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

debug:
	$(CC) $(SRCS) $(CFLAGS) -ggdb3

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

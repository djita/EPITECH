##
## Makefile for Makefile in /home/bigup/prog/tek2/proj/
##
## Made by dimitri doyen
## Login   <doyen_d@epitech.net>
##
## Started on  Sat Feb 26 18:28:10 2011 dimitri doyen
## Last update Sun Mar  3 02:53:53 2013 Lyoma Guillou
##

###############
# Definitions #
###############

NAME    = my_script

SRCS    = loop.c \
        my_logintty.c \
        my_forktty.c \
        my_opentty.c \
        main.c \
        check_args.c

OBJS    = $(SRCS:.c=.o)

CC      = gcc

CFLAGS  = -W -Wall -Werror -Wextra -std=c99 -ggdb3

AR      = ar r

RM      = rm -rf

#############################
# Complilation Instructions #
#############################

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean   :
	$(RM) *.o

fclean  :
	$(RM) *.o $(NAME)

re      : clean all


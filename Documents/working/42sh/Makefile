##
## Makefile for 42sh in /mnt/fedora_std/home/falck_m/Work/42sh
##
## Made by mickael falck
## Login   <falck_m@epitech.net>
##
## Started on  Sun Apr 15 15:12:57 2012 mickael falck
## Last update Sun May 20 21:41:04 2012 vincent bonmarchand
##

# Das Makefile v2.0 by falck_m

NAME	=	HIsh
DEBUG	=	no

CC	:=	$(if $(filter yes, $(DEBUG)),clang,gcc)
RM	=	rm -f
SRCDIR	=	./src

ifeq ($(wildcard $(SRCDIR)/testmain.c),)
  SRC	=	$(SRCDIR)/main.c
else
  SRC	=	$(SRCDIR)/$(if $(filter yes, $(DEBUG)),testmain.c,main.c)
endif
SRC	+=	$(SRCDIR)/termcaps.c		\
		$(SRCDIR)/execute.c		\
		$(SRCDIR)/readline.c		\
		$(SRCDIR)/parse_caps.c		\
		$(SRCDIR)/caps.c		\
		$(SRCDIR)/errors.c		\
		$(SRCDIR)/history.c		\
		$(SRCDIR)/list.c		\
		$(SRCDIR)/funny.c		\
		$(SRCDIR)/char_type.c		\
		$(SRCDIR)/ll_operat2.c		\
		$(SRCDIR)/ll_operat.c		\
		$(SRCDIR)/ll_scripts.c		\
		$(SRCDIR)/lltree.c		\
		$(SRCDIR)/rec_tree.c		\
		$(SRCDIR)/tree_funcs.c		\
		$(SRCDIR)/env_addenv.c		\
		$(SRCDIR)/env.c			\
		$(SRCDIR)/env_getenv.c		\
		$(SRCDIR)/func_tab.c		\
		$(SRCDIR)/my_strndup.c		\
		$(SRCDIR)/built_cd.c		\
		$(SRCDIR)/built_env.c		\
		$(SRCDIR)/built_echo.c		\
		$(SRCDIR)/built_pwd.c		\
		$(SRCDIR)/exec_endl.c		\
		$(SRCDIR)/exec_cmd.c		\
		$(SRCDIR)/exec_pipe.c		\
		$(SRCDIR)/exec_logop.c		\
		$(SRCDIR)/exec_builtin.c	\
		$(SRCDIR)/exec_redir.c		\
		$(SRCDIR)/str_to_wordtab.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	:=	$(if $(filter yes, $(DEBUG)),-g -ggdb -O0,-O2)
CFLAGS	+=	-W -Wall -Wextra -pedantic -ansi -I./include
CFLAGS	+=	-D_BSD_SOURCE
LDFLAGS	=	-lncurses

all:		$(SRC) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

%.o:		%.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

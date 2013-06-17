##
##
## Here is a makefile for EPITECH's ruby projects
## Rakefiles are not available on the original dump
## The Makefile copies the sources from the .rb file
## To an executable file
##
## This is meant to simulate a Rakefile
##
##

MODE	=	chmod
NAME	=	205QI
SRCS	=	$(NAME).rb
RM	=	rm

all:	
	cat src/$(SRCS) > ./$(NAME)
	$(MODE) +x $(NAME)

clean:	
	$(RM) $(NAME)

re:	clean all
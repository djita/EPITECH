/*
** main.c for 42sh in /home/falck_m/Work/42sh
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Tue Mar 06 21:29:28 2012 mickael falck
** Last update Sat May 12 16:37:33 2012 lyoma guillou
*/

#define _BSD_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <strings.h>

#include "lltree.h"
#include "my.h"
#include "42sh.h"

void		handle_signal(int signo)
{
  if (signo)
    my_putstr("\n$>");
}

void		show_tree(t_cmd *tree)
{
  if (tree->prev)
    show_tree(tree->prev);
  if (tree->next)
    show_tree(tree->next);
  printf("%s\n", tree->name);
}

int		main(int argc, char *argv[], char **envp)
{
  int		len;
  char		*buff;
  /* t_cmd		*list; */
  t_token_list	*list;
  t_token_list	*tmp;

  (void) argc;
  (void) argv;
  (void) envp;
  len = 1;
  buff = malloc(1024 * sizeof(buff));
  bzero(buff, 1024);
  signal(SIGINT, handle_signal);
  while (len != 0)
    {
      my_putstr("$>");
      if ((len = read(0, buff, 1023)) > 0)
	{
	  /*
	    list = line_parser(buff, len);
	    if (list != NULL)
	    {
	    show_tree(list);
	    free_cmdl(list);
	    }
	  */
	  list = tokenise(buff, len);
	  tmp = list;
	  while (tmp)
	    {
	      printf("%s\n", tmp->token);
	      tmp = tmp->next;
	    }
	  free_l2c(list);
	}
      bzero(buff, 1024);
    }
  printf("\n");
  return (0);
}

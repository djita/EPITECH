/*
** main.c for 42sh in /home/falck_m/Work/42sh
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Tue Mar 06 21:29:28 2012 mickael falck
** Last update Sun May 20 14:15:00 2012 lyoma guillou
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include "termcaps.h"
#include "lltree.h"
#include "readline.h"
#include "env.h"
#include "my.h"

void		handle_signal(int signo)
{
  if (signo)
    write(1, "\n$>", strlen("\n$>"));
}

void		show_tree(t_cmd *tree)
{
  if (tree)
    {
      if (tree->left)
	show_tree(tree->left);
      if (tree->right)
	show_tree(tree->right);
    }
}

int		main(int argc, char *argv[], char **envp)
{
  char		*buff;
  t_cmd		*list;

  (void) argc;
  (void) argv;
  (void) envp;
  /* signal(SIGINT, handle_signal); */
  init_envp(envp);
  init_termcap();
  while ((buff = readline()))
    if (strlen(buff) > 0)
      {
	list = line_parser(buff, strlen(buff));
	if (check_parser(list))
	  show_tree(list);
	free_cmdl(list);
      }
  write(1, "\n", strlen("\n"));
  return (0);
}

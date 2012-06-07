/*
** execute.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 18 20:03:52 2012 mickael falck
** Last update Sun May 20 20:22:16 2012 mickael falck
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "history.h"
#include "execute.h"
#include "lltree.h"

static const t_exec	g_e_hand[]=
  {
    {CMDS, exec_cmd},
    {PIPE, exec_pipe},
    {RDRC, exec_redir},
    {OLOG, exec_logop},
    {ENDL, exec_endl},
    {NIL, NULL}
  };

int		exec_node(t_cmd *node, int fds[2], int *stop)
{
  int		i;

  i = 0;
  if (node)
    {
      while (g_e_hand[i].flag && !(g_e_hand[i].flag & node->flag))
	++i;
      if (g_e_hand[i].flag != 0)
	return (g_e_hand[i].fnc(node, fds, stop));
    }
  return (EXIT_FAILURE);
}

int		exec_tree(t_cmd *tree, int *stop)
{
  int		fds[2];

  fds[0] = 0;
  fds[1] = 1;
  if (tree)
    return (exec_node(tree, fds, stop));
  return (EXIT_FAILURE);
}

int		execute(char *buff, int *stop)
{
  t_cmd		*tree;
  int		ret;

  printf("User input [%s]\n", buff);
  ret = EXIT_SUCCESS;
  if (buff[0])
    append_hist(buff);
  if (!strcmp(buff, "history"))
    print_history();
  else if (!strcmp(buff, "exit"))
    *stop = 1;
  else
    {
      tree = line_parser(buff, strlen(buff));
      if (tree != NULL)
	{
	  ret = exec_tree(tree, stop);
	  free_cmdl(tree);
	}
    }
  return (ret);
}

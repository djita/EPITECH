/*
** history.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 17:38:15 2012 mickael falck
** Last update Sun May 20 19:42:55 2012 vincent bonmarchand
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "errors.h"

t_history		*get_history(void)
{
  static t_history	history = {NULL, NULL};

  return (&history);
}

void	free_cmd(void *ptr)
{
  t_hcmd	*cmd;

  cmd = ptr;
  if (cmd)
    {
      free(cmd->cmd);
      free(cmd);
    }
}

void		free_history(void)
{
  t_history	*history;

  history = get_history();
  flush_list(history->cmds, free_cmd);
  if (history->savepath)
    free(history->savepath);
}

void		append_hist(char *cmd)
{
  static size_t	id = 1;
  t_history	*history;
  t_list	*list;
  t_list	*cur;
  t_list	*tmp;
  t_hcmd	*new;

  if (cmd)
    {
      history = get_history();
      list = history->cmds;
      cur = list;
      if ((new = malloc(sizeof(*new))) == NULL)
	{
	  my_err("History", ERR_MALLOC, CONTINUE);
	  return;
	}
      new->id = id;
      new->cmd = strdup(cmd);
      while (cur && cur->next)
	cur = cur->next;
      tmp = add_link(cur, new);
      history->cmds = (list) ? list : tmp;
      ++id;
    }
}

void		print_history(void)
{
  t_history	*history;
  t_list	*list;
  t_hcmd		*cmd;

  history = get_history();
  list = history->cmds;
  while (list)
    {
      cmd = (t_hcmd *)list->data;
      if (cmd && cmd->id && cmd->cmd)
	printf("%5lu\t%s\n", cmd->id, cmd->cmd);
      list = list->next;
    }
}

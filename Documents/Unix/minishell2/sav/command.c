/*
** command.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec 30 15:01:38 2011 lyoma guillou
** Last update Mon Feb 13 17:06:53 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "my_sh.h"

static void	_cmd_not_found(char *cmd)
{
  my_puterr(cmd);
  my_puterr(": Command not found\n");
}

void		cmd_to_exec(char *src, char **env)
{
  char		**arg;
  char		**tab;
  int		i;

  i = 0;
  arg = my_str_to_wordtab(src);
  if (arg && arg[0])
    {
      tab = insert_cmd(path_tab(arg[0], get_path(env)));
      if (fork() == 0)
	{
	  while (tab[i] && execve(tab[i], arg, env) < 0)
	    ++i;
	  if (tab[i] == '\0')
	    _cmd_not_found(tab[0]);
	  exit(EXIT_SUCCESS);
	}
      else
	wait(NULL); 
    }
}

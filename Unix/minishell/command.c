/*
** command.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec 30 15:01:38 2011 lyoma guillou
** Last update Sun Jan  1 22:50:18 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "my_sh.h"

void	call_exec(char *cmd, char **arg, char **env)
{
  int	i;

  i = 0;
  if (fork() == 0)
    {
      i = execve(cmd, arg, env);
      if (i < 0)
	{
	  my_putstr(cmd);
	  my_putstr(": Command not found\n");
	  exit(EXIT_SUCCESS);
	}
    }
  else
    wait(NULL);
}

void	cmd_to_exec(char *src, char **env)
{
  char	**arg;
  char	*cmd;
  int	i;

  i = 0;
  arg = my_str_to_wordtab(src);
  if (arg && arg[0])
    {
      cmd = my_strdup(arg[0]);
      call_exec(cmd, arg, env);
      free(cmd);
    }
}

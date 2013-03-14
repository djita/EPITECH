/*
** env_functions.c for env in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Fri May 18 18:55:32 2012 vincent bonmarchand
** Last update Sun May 20 21:27:22 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "env.h"

char		***get_envp()
{
  static char	**env_p = NULL;

  return (&env_p);
}

int	aff_env(int fd[2])
{
  char	***tmp;
  int	curs;

  curs = 0;
  tmp = get_envp();
  while ((*tmp)[curs] != NULL)
    {
      write(fd[1], (*tmp)[curs], strlen((*tmp)[curs]));
      write(fd[1], "\n", 1);
      curs++;
    }
  return (0);
}

int	remove_env(char **arg)
{
  char	***old_env;
  char	**tmp;
  int	count;
  int	count2;

  count = 0;
  count2 = 0;
  old_env = get_envp();
  tmp = malloc((count_elemenv(*old_env) + 1) * sizeof(*tmp));
  if (tmp == NULL)
    return (-1);
  while ((*old_env)[count] != NULL)
    {
      if (strncmp(getname(arg), (*old_env)[count],
		  (strlen(getname(arg) + 1))) != 0)
	{
	  tmp[count2] = (*old_env)[count];
	  count2++;
	}
      count++;
    }
  tmp[count2] = NULL;
  *old_env = tmp;
  return (0);
}

void	free_env()
{
  char	***env;
  int	i;

  i = 0;
  env = get_envp();
  while ((*env)[i] != NULL)
    {
      free((*env)[i]);
      i++;
    }
  free(*env);
}

int	init_envp(char **env)
{
  int	count;
  char	***tmp;

  count = 0;
  tmp = get_envp();
  if (env == NULL)
    return (-1);
  *tmp = malloc((count_elemenv(env) + 1) * sizeof(*tmp));
  while (env[count] != NULL)
    {
      (*tmp)[count] = strdup(env[count]);
      count++;
    }
  (*tmp)[count] = NULL;
  return (0);
}

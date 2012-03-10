/*
** envp.c for my_sh in /home/guillo_e//SVNdepot/minishell1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Jan  1 21:53:35 2012 lyoma guillou
** Last update Mon Jan 16 19:03:23 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

char	**copy_envp(char **envp)
{
  char	**tab;
  int	i;

  i = -1;
  if ((tab = malloc((my_tablen(envp) + 1) * sizeof(**tab))) == NULL)
    {
      my_putstr("Environment could not be allocated\n");
      exit(EXIT_FAILURE);
    }
  tab = my_tabset(tab, my_tablen(envp) + 1);
  while (envp[++i])
    tab[i] = my_strdup(envp[i]);
  return (tab);
}

char	*get_path(char **my_env)
{
  int	cnt;

  cnt = 0;
  while (my_env[cnt])
    {
      if (my_strncmp(my_env[cnt], "PATH", my_strlen("PATH")) == 0)
	return (my_env[cnt]);
      cnt++;
    }
  my_putstr("$PATH does not exist\n");
  return (NULL);
}

void	search_path(char *path)
{
  int	ind;

  ind = 0;
  while (path[ind])
    {
      
    }
}

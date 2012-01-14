/*
** envp.c for my_sh in /home/guillo_e//SVNdepot/minishell1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Jan  1 21:53:35 2012 lyoma guillou
** Last update Sun Jan  1 22:32:31 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

char	**copy_envp(char **envp)
{
  char	**tab;
  int	i;

  i = 0;
  if ((tab = malloc((my_tablen(envp) + 1) * sizeof(**tab))) == NULL)
    return (NULL);
  tab = my_tabset(tab, my_tablen(envp) + 1);
  while (envp[i])
    {
      tab[i] = my_strdup(envp[i]);
      i++;
    }
  return (tab);
}

char	*get_path(char **my_env)
{
  int	cnt;

  cnt = 0;
  while (my_env[cnt])
    {
      if (my_strcmp(my_env[cnt], "PATH") == 0)
	return (my_strdup(my_env[cnt]));
      cnt++;
    }
  return (NULL);
}

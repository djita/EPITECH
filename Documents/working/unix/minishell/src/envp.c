/*
** envp.c for my_sh in /home/guillo_e//SVNdepot/minishell1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Jan  1 21:53:35 2012 lyoma guillou
** Last update Fri Feb 10 18:56:14 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

char	*get_path(char **my_env)
{
  int	cnt;

  cnt = 0;
  while (my_env[cnt])
    {
      if (my_strncmp(my_env[cnt], "PATH", my_strlen("PATH") - 1) == 0)
	return (my_env[cnt]);
      ++cnt;
    }
  my_putstr("$PATH does not exist\n");
  exit(EXIT_FAILURE);
}

char	**path_tab(char *cmd, char *path)
{
  char	**cmd_tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((cmd_tab = malloc(MAX_PATH * sizeof(*cmd_tab))) == NULL)
    return (NULL);
  my_memset(cmd_tab, 0, MAX_PATH);
  cmd_tab[j] = cmd;
  while (path[i++] != '=');
  --i;
  while (path[i])
    {
      if (path[i] == ':' || path[i] == '=')
	{
	  ++i;
	  k = 0;
	  if ((cmd_tab[++j] = malloc(PATH_LEN * sizeof(**cmd_tab))) == NULL)
	    return (NULL);
	}
      cmd_tab[j][k++] = path[i++];
    }
  return (cmd_tab);
}

char	**insert_cmd(char **path_list)
{
  int	i;

  i = 0;
  while (path_list[++i])
    {
      my_strcat(path_list[i], "/");
      my_strcat(path_list[i], path_list[0]);
    }
  return (path_list);
}

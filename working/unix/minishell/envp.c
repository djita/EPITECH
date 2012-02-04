/*
** envp.c for my_sh in /home/guillo_e//SVNdepot/minishell1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Jan  1 21:53:35 2012 lyoma guillou
** Last update Tue Jan 31 17:48:55 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

char	**copy_envp(char **envp)
{
  char	**tab;
  int	i;

  i = 0;
  if ((tab = malloc((my_strlen((char *) envp) + 1) * sizeof(**tab))) == NULL)
    {
      my_putstr("Environment could not be allocated\n");
      exit(EXIT_FAILURE);
    }
  tab = my_memset(tab, 0, my_strlen((char *) envp) + 1);
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
      if (my_strncmp(my_env[cnt], "PATH", my_strlen("PATH") - 1) == 0)
	return (my_env[cnt]);
      cnt++;
    }
  my_putstr("$PATH does not exist\n");
  return (NULL);
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

char	**insert_cmd(char *cmd, char **path_list)
{
  int	i;

  i = 0;
  while (path_list[++i])
    {
      path_list[i] = my_strncat(path_list[i], "/", 1);
      path_list[i] = my_strncat(path_list[i], cmd, my_strlen(cmd));
    }
  return (path_list);
}

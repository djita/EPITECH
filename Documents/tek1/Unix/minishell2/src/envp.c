/*
** envp.c for my_sh in /home/guillo_e//SVNdepot/minishell1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Jan  1 21:53:35 2012 lyoma guillou
** Last update Sun Mar  4 11:41:43 2012 lyoma guillou
*/

#include <my_sh.h>

char		**copy_envp(char **envp)
{
  char		**my_env;
  int		i;

  i = 0;
  my_env = xmalloc(ENV_SIZE * sizeof(*my_env));
  my_memcpy(my_env, envp, my_tablen(envp));
  return (my_env);
}

char		**path_tab(char *cmd, char *path)
{
  char		**cmd_tab;
  int		i;
  int		j;
  int		k;

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

char		**insert_cmd(char **path_list)
{
  int		i;

  i = 0;
  while (path_list[++i])
    {
      my_strcat(path_list[i], "/");
      my_strcat(path_list[i], path_list[0]);
    }
  return (path_list);
}

void		shell_init(char **my_env)
{
  char		buffer[BUFF_SIZE];
  int		len;

  len = 1;
  my_memset(buffer, 0, BUFF_SIZE);
  while (len != 0)
    {
      my_putstr("$>");
      signal(SIGINT, SIG_IGN);
      signal(SIGINT, handle_signal);
      if ((len = read(0, buffer, BUFF_SIZE - 1)) > 1)
	if ((cmd_to_exec(buffer, my_env)) == 0)
	  return;
      my_memset(buffer, 0, BUFF_SIZE);
    }
  return;
}

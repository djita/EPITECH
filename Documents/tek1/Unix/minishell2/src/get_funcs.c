/*
** get_funcs.c for minishell in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar  2 18:11:58 2012 lyoma guillou
** Last update Fri Mar  2 19:00:51 2012 lyoma guillou
*/

#include <my_sh.h>

char		*get_path(char **my_env)
{
  int		cnt;

  cnt = 0;
  while (my_env[cnt])
    {
      if (!my_strncmp(my_env[cnt], "PATH", my_strlen("PATH") - 1))
	return (my_env[cnt]);
      ++cnt;
    }
  my_putstr("$PATH does not exist\n");
  exit(EXIT_FAILURE);
}

char		*my_getenv(char *name, char **my_env)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(name);
  while (my_env[i])
    {
      if (!my_strncmp(name, my_env[i], len - 1))
	return (my_env[i] + len + 1);
      ++i;
    }
  return (NULL);
}

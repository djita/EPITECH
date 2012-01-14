/*
** main.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:12:12 2011 lyoma guillou
** Last update Sun Jan  1 22:40:33 2012 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "my_sh.h"

int	main(int ac, char **av, char **envp)
{
  int	len;
  char	*buffer;
  char	**my_env;

  if (ac != 1 || !av[0] || (buffer = malloc(4096 * sizeof(*buffer))) == NULL)
    return (0);
  len = 1;
  buffer = my_strset(buffer, 4096);
  my_env = copy_envp(envp);
  while (len != 0)
    {
      my_putstr("$>");
      len = read(0, buffer, 4095);
      if (len > 1)
	cmd_to_exec(buffer, my_env);
      buffer = my_strset(buffer, len);
    }
  my_putstr("Exiting");
  return (0);
}

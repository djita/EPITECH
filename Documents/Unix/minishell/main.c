/*
** main.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:12:12 2011 lyoma guillou
** Last update Mon Jan 16 18:46:25 2012 lyoma guillou
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
    {
      my_putstr("buffer allocation problem\n");
      return (0);
    }
  len = 1;
  buffer = my_strset(buffer, 4096);
  my_env = copy_envp(envp);
  buffer = get_path(my_env);
  my_putstr(buffer);
  /*
    while (len != 0)
    {
    my_putstr("$>");
    len = read(0, buffer, 4095);
    if (len > 1)
    cmd_to_exec(buffer, my_env);
    buffer = my_strset(buffer, len);
    }
  */
  my_putstr("Exiting\n");
  return (0);
}

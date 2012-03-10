/*
** main.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:12:12 2011 lyoma guillou
** Last update Tue Jan 31 17:39:10 2012 lyoma guillou
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
  int	i;
  char	**tab;
  int	j;

  i = 0;
  if (ac != 1 || !av[0] || (buffer = malloc(4096 * sizeof(*buffer))) == NULL)
    {
      my_putstr("buffer allocation problem\n");
      return (0);
    }
  len = 1;
  buffer = my_memset(buffer, 0, 4096);
  my_env = copy_envp(envp);
  buffer = get_path(my_env);
  tab = path_tab("ls", buffer);
  tab = insert_cmd("ls", tab);
  for (j = 0; tab[j]; j++)
    printf("%s\n", tab[j]);
    
  /*
    while (len != 0)
    {
    my_putstr("$>");
    len = read(0, buffer, 4095);
    if (len > 1)
    cmd_to_exec(buffer, my_env);
    buffer = my_memset(buffer, 0, len);
    }
  */

  my_putstr("Exiting\n");
  return (0);
}

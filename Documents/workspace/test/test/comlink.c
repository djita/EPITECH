/*
** comlink.c for comlink in /home/guillo_e/Documents/workspace/test/test
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  6 13:36:49 2013 Lyoma Guillou
** Last update Mon May  6 13:49:28 2013 Lyoma Guillou
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>

void		set_opt(char **av)
{
  (void) av;
}

int		main(int ac, char **av)
{
  char		*buff;
  size_t	len;

  if (ac > 1)
    set_opt(av);
  while (-1 != getline(&buff, &len, stdin))
    {
      printf("%s", buff);
      if (!strcmp("exit\n", buff))
	break;
    }
  return 0;
}

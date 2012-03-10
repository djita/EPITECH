/*
** my_getnbr.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan  6 17:13:00 2012 lyoma guillou
** Last update Fri Jan  6 17:41:46 2012 lyoma guillou
*/

#include <stdlib.h>
#include "push_swap.h"

int		is_numeric(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (is_numeric(str[i]))
    {
      x = x * 10;
      x = x + str[i] - '0';
      ++i;
    }
  return (x);
}

int		*my_get_int_tab(int ac, char **av)
{
  int		i;
  int		*tab;

  i = 1;
  if ((tab = malloc(ac * sizeof(*tab))) == NULL)
    return (NULL);
  while (av[i])
    {
      tab[i - 1] = my_getnbr(av[i]);
      ++i;
    }
  return (tab);
}

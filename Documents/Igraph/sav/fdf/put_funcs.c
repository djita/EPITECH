/*
** put_funcs.c for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec  9 14:12:18 2011 lyoma guillou
** Last update Fri Dec  9 20:08:01 2011 lyoma guillou
*/

#include <unistd.h>
#include "fdf.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

/*
** my_getfuncs.c for wolf3d in 
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 15:11:18 2012 lyoma guillou
** Last update Sat Jan 14 17:27:09 2012 lyoma guillou
*/

#include "map.h"

int		my_gettablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i++]);
  return (i);
}

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      x = x * 10;
      x = x + (str[i++] - '0');
    }
  return (x);
}

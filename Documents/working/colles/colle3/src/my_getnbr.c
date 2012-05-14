/*
** my_getnbr.c for  in /home/guillo_e//Documents/working/colles/colle3/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 20:59:04 2012 lyoma guillou
** Last update Mon Apr 30 21:04:17 2012 lyoma guillou
*/

#include "map.h"

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (is_num(str[i]))
    {
      x = x * 10 + (str[i] - '0');
      ++i;
    }
  return (x);
}

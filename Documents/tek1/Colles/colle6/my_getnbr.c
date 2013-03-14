/*
** main.c for colles6 in /home/leduc_v//colles6
** 
** Made by victor leduc
** Login   <leduc_v@epitech.net>
** 
** Started on  Mon May 21 19:28:29 2012 victor leduc
** Last update Mon May 21 20:08:53 2012 lyoma guillou
*/

#include "utils.h"

int		my_getnbr(char *str)
{
  int		nb;
  int		mult;
  int		i;

  nb = 0;
  mult = 1;
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      if (str[i] < '0' || '9' < str[i])
	return (-1);
      nb = nb + (str[i] - '0') * mult;
      i--;
      mult *= 10;
    }
  return (nb);
}

/*
** my_atoi_base.c for my_atoi_base in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 19 10:43:34 2012 exam_user
** Last update Thu Jan 19 11:25:29 2012 exam_user
*/

#include "my_atoi_base.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i);
}

int	my_power_it(int nb, int pow)
{
  int	x;

  x = 1;
  while (pow > 0)
    {
      x = x * nb;
      pow--;
    }
  return (x);
}

int	my_atoi_base(char *str, char *base)
{
  int	x;
  int	i;
  int	j;
  int	b_len;

  x = 0;
  i = my_strlen(str) - 2;
  b_len = my_strlen(base) - 1;
  while (i >= 0)
    {
      j = 0;
      while (str[i] != base[j])
	j++;
      x = x + (j * (my_power_it(b_len, my_strlen(str) - (i + 2))));
      i--;
    }
  return (x);
}

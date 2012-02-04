/*
** my_getnbr.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 17:09:16 2012 louis duverdier
** Last update Thu Jan 26 17:24:36 2012 louis duverdier
*/

#include <corewar.h>

int		my_getnbr(const char *d)
{
  int	i;
  int	value;
  int	neg;

  i = 0;
  value = 0;
  neg = 0;
  while (d[i] == '-')
    neg = !neg;
  while (my_is_number(d[i]))
    {
      value = value * 10 + d[i] - '0';
      ++i;
    }
  return (neg ? value * -1 : value);
}

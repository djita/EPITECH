/*
** my_getnbr.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Feb 21 10:21:10 2012 louis duverdier
** Last update Wed Mar 21 18:03:44 2012 louis duverdier
*/

#include "corewar.h"

int	my_getnbr(const char *d)
{
  int	i;
  int	value;
  int	neg;

  i = 0;
  value = 0;
  neg = 0;
  while (d[i] == '-')
    {
      neg = !neg;
      ++i;
    }
  while (my_is_number(d[i]))
    {
      value = value * 10 + d[i] - '0';
      ++i;
    }
  return (neg ? value * -1 : value);
}

static int	_index_of(char c, const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (i);
      ++i;
    }
  return (-1);
}

int		my_getnbr_hex(const char *d)
{
  int		i;
  unsigned int	value;
  const char	*base;

  i = 0;
  value = 0;
  base = "0123456789ABCDEF";
  while ((d[i] >= '0' && d[i] <= '9')
         || (d[i] >= 'A' && d[i] <= 'Z'))
    {
      value = value * 16 + _index_of(d[i], base);
      ++i;
    }
  return (value);
}

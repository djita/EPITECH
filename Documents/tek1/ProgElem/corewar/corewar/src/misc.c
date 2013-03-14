/*
** misc.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Mar 15 12:23:02 2012 louis duverdier
** Last update Thu Mar 15 12:29:31 2012 louis duverdier
*/

#include "corewar.h"

static int	_nbrlen(unsigned int n)
{
  int		len;

  len = 1;
  while (n)
    {
      n /= 10;
      ++len;
    }
  return (len);
}

char	*number_to_str(unsigned int n)
{
  int	len;
  int	tmp;
  char	*ret;

  len = _nbrlen(n) - 1;
  tmp = len;
  ret = xmalloc((len + 1) * sizeof(*ret));
  while (len)
    {
      ret[len - 1] = (n % 10) + '0';
      n /= 10;
      --len;
    }
  ret[tmp] = 0;
  return (ret);
}

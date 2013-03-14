#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

static void	get_pow(int nb, char *count)
{
  if (nb < 0)
    {
      get_pow(nb / 10, count);
      if (!putchar('0' + (-(nb % 10))))
	*count = -128;
      else
	++*count;
    }
  else if (nb > 0)
    {
      get_pow(nb / 10, count);
      if (!putchar('0' + (nb % 10)))
	*count = -128;
      else
	++*count;
    }
}

char	my_put_nbr(int nb)
{
  char	count = 0;

  if (nb < 0)
    {
      ++count;
      if (!putchar('-'))
	return (-1);
    }
  if (nb != 0)
    get_pow(nb, &count);
  else
    {
      ++count;
      if (!putchar('0'))
	return (-1);
    }
  return (count);
}

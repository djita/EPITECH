/*
** convert_base.c for convert_base in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct 12 09:32:14 2011 lyoma guillou
** Last update Wed Oct 12 21:39:39 2011 lyoma guillou
*/

#include <stdlib.h>

int			lenght_num(unsigned int nb, int base_len)
{
  int			i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / base_len;
      i = i + 1;
    }
  return (i);
}

char			*convert_to_base(unsigned int nb, char *base_to, char *dst)
{
  int			i;
  int			base_len;
  int			x;

  base_len = my_strlen(base_to);
  i = lenght_num(nb, base_len) - 1;
  x = 0;
  while (i >= 0)
    {
      x = nb % base_len;
      dst[i] = base_to[x];
      nb = nb / base_len;
      i--;
    }
  dst[my_strlen(dst)] = '\0';
  return (dst);
}

int			convert_to_dec(char *nbr, char *base_from)
{
  int			i;
  int			j;
  unsigned int		x;

  i = 0;
  x = 0;
  while (i < my_strlen(nbr))
    {
      j = 0;
      while (nbr[my_strlen(nbr) - 1 - i] != base_from[j])
	j++;
      x = x + (j * my_power_rec(my_strlen(base_from), i));
      i++;
    }
  return (x);
}

char			*convert_base(char *nbr, char *base_from, char *base_to)
{
  char			*num;
  unsigned int		x;
  int			base_len;

  x = convert_to_dec(nbr, base_from);
  base_len = my_strlen(base_to);
  num = malloc((lenght_num(x, base_len) + 1) * sizeof(char));
  if (num == NULL)
    return (0);
  num = convert_to_base(x, base_to, num);
  return (num);
}

int			main(int ac, char **av)
{
  my_putstr(convert_base(av[1], av[2], av[3]));
  my_putchar('\n');
}

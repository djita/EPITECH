/*
** dump.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Mar 13 20:39:57 2012 louis duverdier
** Last update Thu Mar 15 11:03:48 2012 louis duverdier
*/

#include "corewar.h"

static void	_print_label(int c)
{
  int		i;
  char		buff[4];
  const char	*data;

  i = 4;
  if (c != 0)
    my_putchar('\n');
  data = "0123456789ABCDEF";
  while (i)
    {
      buff[i - 1] = data[c % 16];
      c /= 16;
      --i;
    }
  write(1, buff, 4);
  my_putstr(" :");
}

static void	_put_hex(unsigned char c)
{
  char		buff[2];
  const char	*data;

  data = "0123456789abcdef";
  buff[0] = data[(c / 16) % 16];
  buff[1] = data[c % 16];
  write(1, buff, 2);
}

void	dump_memory(t_handler *h)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (i % 16 == 0)
        _print_label(i);
      if (i % 16 != 16)
        my_putchar(' ');
      _put_hex(h->mem[i] & 0xFF);
      i += 1;
    }
  my_putchar('\n');
}

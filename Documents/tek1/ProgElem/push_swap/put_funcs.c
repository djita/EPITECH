/*
** put_funcs.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 20:26:41 2012 lyoma guillou
** Last update Sun Jan  8 17:05:31 2012 lyoma guillou
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i++]);
  write(1, str, i);
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -10)
	my_putnbr(nb / -10);
      my_putchar(((nb % 10) * -1) + '0');
    }
  else
    {
      if (nb >= 10)
	my_putnbr(nb / 10);
      my_putchar((nb % 10) + '0');
    }
}

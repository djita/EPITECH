/*
** str_manip.c for my_std in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique/my_std
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Nov 02 15:30:25 2011 mickael falck
** Last update Fri Nov 04 10:38:29 2011 mickael falck
*/

#include <stdlib.h>
#include "str_manip.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_put_estr(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -10)
	my_putnbr(nb / -10);
      my_putchar((nb % -10) + '0');
    }
  else
    {
      if (nb >= 10)
	my_putnbr(nb / 10);
      my_putchar((nb % 10) + '0');
    }
}

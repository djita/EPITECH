/*
** my_putnbr.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:31 2012 louis duverdier
*/

#include <my.h>

void	my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb < 0 ? (nb <= -10) : (nb >= 10))
    my_putnbr(nb / ((nb < 0) ? -10 : 10));
  my_putchar((nb < 0 ? (-(nb % -10)) : (nb % 10)) + '0');
}

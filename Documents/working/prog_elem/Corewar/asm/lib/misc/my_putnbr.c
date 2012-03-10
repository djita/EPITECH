/*
** my_putnbr.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 16:37:09 2012 louis duverdier
** Last update Wed Jan 18 16:58:08 2012 louis duverdier
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

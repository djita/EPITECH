/*
** my_put_nbr.c for my_put_nbr in /home/guillo_e//afs/rendu/piscine/Jour_03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct  5 12:12:13 2011 lyoma guillou
** Last update Wed Nov 16 14:35:49 2011 lyoma guillou
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int		ten;
  int		neg;
  char		zero;

  ten = 10;
  neg = -1;
  zero = '0';
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -ten)
	my_put_nbr(nb / -ten);
      my_putchar((neg * (nb % -ten)) + zero);
    }
  else
    {
      if (nb >= ten)
	my_put_nbr(nb / ten);
      my_putchar((nb % ten) + zero);
    }
}

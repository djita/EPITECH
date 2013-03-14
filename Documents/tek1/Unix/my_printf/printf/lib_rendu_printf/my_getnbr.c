/*
** my_getnbr.c for my_getnbr in /home/guillo_e//afs/rendu/piscine/Jour_04/ex_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct  6 10:56:32 2011 lyoma guillou
** Last update Wed Nov 16 14:42:43 2011 lyoma guillou
*/

#include "my.h"

int     is_over_int(int nb, char sp)
{
  int   i;

  i = 214748364;
  if (nb <= i || nb >= -i)
    {
      if (nb <= -i && sp > '8')
        return (-1);
      if (nb >= i && sp > '7')
        return (-1);
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	neg;

  nb = 0;
  i = 0;
  neg = 1;
  while (str[i])
    {
      if (str[i] == '-')
	neg = -neg;
      if (is_num(str[i]) == 1)
	{
	  if (is_over_int((nb * neg), str[i]) == -1)
	    return (0);
	  nb = nb * 10;
	  nb = nb + (str[i] - '0');
	}
      if (str[i] != '-' && str[i] != '+' && is_num(str[i]) == -1)
     	return (nb * neg);
      i++;
    }
  return (nb * neg);
}

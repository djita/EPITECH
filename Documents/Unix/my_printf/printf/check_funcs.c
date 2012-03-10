/*
** check_funcs.c for  in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov  9 21:23:43 2011 lyoma guillou
** Last update Fri Nov 11 11:50:40 2011 lyoma guillou
*/

#include "my_printf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_numlen(unsigned int nb, int base_len)
{
  int   i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / base_len;
      i = i + 1;
    }
  return (i);
}

int     is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (-1);
}

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
  nb = nb * neg;
  return (nb);
}

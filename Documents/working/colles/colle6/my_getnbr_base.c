/*
** get_nbr_base.c for carre in /home/leduc_v//colles6
** 
** Made by victor leduc
** Login   <leduc_v@epitech.net>
** 
** Started on  Mon May 21 20:47:56 2012 victor leduc
** Last update Mon May 21 21:26:50 2012 marc deletang
*/

#include	"utils.h"

int		my_getnbr_base(char *str, char *base)
{
  int		i;
  int		j;
  int		nb;
  int		base_len;
  int		mult;

  i = my_strlen(str) - 1;
  base_len = my_strlen(base);
  mult = 1;
  nb = 0;
  while (i >= 0)
    {
      j = 0;
      while (str[i] != base[j] && base[j] != '\0')
	j++;
      if (base[j] == '\0')
	return (-1);
      nb += j * mult;
      mult *= base_len;
      i--;
    }
  return (nb);
}

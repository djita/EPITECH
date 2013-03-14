/*
** put_funcs.c for bsq in /home/guillo_e//working/prog_elem/bsq
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Dec  5 18:41:27 2011 lyoma guillou
** Last update Mon Dec  5 19:24:43 2011 lyoma guillou
*/

#include <unistd.h>
#include "bsq.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  write(1, str, i);
}

void		my_puttab(char **map)
{
  int		i;
  int		j;

  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  my_putchar(map[i][j]);
	  j = j + 1;
	}
      my_putchar('\n');
      i = i + 1;
    }
}

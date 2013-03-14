/*
** tab_to_2dtab.c for tab_to_2dtab in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 09:25:29 2013 lyoma guillou
** Last update Thu Jan 10 10:03:36 2013 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>

void		tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int		i;
  int		j;

  *res = malloc(length * sizeof(**res));
  for (i = 0; i < length; ++i)
    {
      (*res)[i] = malloc(width * sizeof(***res));
      for (j = 0; j < width; ++j)
	(*res)[i][j] = tab[(i * width) + (j % width)];
    }
}

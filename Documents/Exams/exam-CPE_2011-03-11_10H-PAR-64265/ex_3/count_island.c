/*
** count_island.c for count_island in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 11 11:08:58 2011 exam_user
** Last update Fri Mar 11 11:12:29 2011 exam_user
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}


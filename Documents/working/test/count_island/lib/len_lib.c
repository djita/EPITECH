/*
** len_lib.c for count_island in /home/guillo_e//Documents/working/test/count_island
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 21:53:44 2012 lyoma guillou
** Last update Sat Mar 10 22:10:24 2012 lyoma guillou
*/

#include <cnd_isl.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

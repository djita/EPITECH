/*
** tab_funcs.c for filler_baby in /home/guillo_e//Documents/working/rush/filler_baby/algo
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 25 15:37:55 2012 lyoma guillou
** Last update Sat Feb 25 15:42:59 2012 lyoma guillou
*/

#include <filler.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

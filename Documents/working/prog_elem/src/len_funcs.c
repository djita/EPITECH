/*
** len_funcs.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 17:47:12 2012 lyoma guillou
** Last update Thu Apr  5 16:24:45 2012 lyoma guillou
*/

#include <parse.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

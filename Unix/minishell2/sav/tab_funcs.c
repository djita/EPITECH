/*
** tab_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 31 15:27:28 2011 lyoma guillou
** Last update Mon Feb 13 17:03:20 2012 lyoma guillou
*/

#include "my_sh.h"

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void		my_showtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i++]);
      my_putchar('\n');
    }
}

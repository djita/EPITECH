/*
** tab_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 31 15:27:28 2011 lyoma guillou
** Last update Tue Jan 31 16:38:09 2012 lyoma guillou
*/

#include "my_sh.h"

void	my_showtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i++]);
      my_putchar('\n');
    }
}

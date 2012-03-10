/*
** tab_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 31 15:27:28 2011 lyoma guillou
** Last update Sun Jan  1 21:58:51 2012 lyoma guillou
*/

#include "my_sh.h"

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i++]);
  return (i);
}

char	**my_tabset(char **tab, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      tab[i] = '\0';
      i++;
    }
  return (tab);
}

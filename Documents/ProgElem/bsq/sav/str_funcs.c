/*
** str_funcs.c for bsq in /home/guillo_e//working/prog_elem/bsq
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Dec  5 19:19:50 2011 lyoma guillou
** Last update Tue Dec  6 16:20:16 2011 lyoma guillou
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "bsq.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i = i + 1;
  return (i);
}

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (str[i])
    {
      x = x * 10;
      x = x + str[i] - '0';
      i = i + 1;
    }
  return (x);
}

char		**my_tab_zero(char **tab, int len)
{
  int		i;

  i = 0;
  while (i <= len)
    {
      tab[i] = 0;
      i = i + 1;
    }
  return (tab);
}

char		*my_strdup(char *str)
{
  char		*dup;
  int		i;

  if ((dup = malloc(my_strlen(str) * sizeof(*dup))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      dup[i] = str[i];
      i = i + 1;
    }
  dup[i] = '\0';
  return (dup);
}

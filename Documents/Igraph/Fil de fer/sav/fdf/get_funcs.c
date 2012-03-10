/*
** get_funcs.c for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec  9 19:58:45 2011 lyoma guillou
** Last update Sun Dec 11 19:47:10 2011 lyoma guillou
*/

#include <stdlib.h>

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  x = 0;
  i = 0;
  while (str[i])
    {
      x = x * 10;
      x = x + str[i] - '0';
      i = i + 1;
    }
  return (x);
}

int		get_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int		*get_line_int(char **tab)
{
  int		*line_data;
  int		i;

  if ((line_data = malloc(get_tablen(tab) * sizeof(*line_data))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i])
    {
      line_data[i] = my_getnbr(tab[i]);
      i = i + 1;
    }
  return (line_data);
}

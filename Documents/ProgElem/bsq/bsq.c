/*
** bsq.c for bsq in /home/guillo_e//working/prog_elem/bsq
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Dec  5 13:39:20 2011 lyoma guillou
** Last update Tue Dec  6 18:56:03 2011 lyoma guillou
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "bsq.h"

void		fill_out(char **tab, int x, int y, int size)
{
  int		i;
  int		j;

  i = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  tab[x + i][y + j] = 'x';
	  j = j + 1;
	}
      i = i + 1;
    }
}

int		pos_chk(char **tab, int x, int y, int size)
{
  int		i;
  int		j;

  i = 0;
  while (tab[x + i] && i < size)
    {
      j = 0;
      while (tab[x + i][y + j] && j < size)
	{
	  if (tab[x + i][y + j] == 'o')
	    return (0);
	  j = j + 1;
	}
      i = i + 1;
    }
  if (i != size || j != size)
    return (0);
  return (1);
}

char		**sqr_chk(char **tab)
{
  int		lim;
  int		i;
  int		j;

  lim = LIM(my_tablen(tab), my_strlen(tab[0]));
  while (lim > 0)
    {
      i = 0;
      while (tab[i])
	{
	  j = 0;
	  while (tab[i][j])
	    {
	      if (pos_chk(tab, i, j, lim) == 1)
		{
		  fill_out(tab, i, j, lim);
		  return (tab);
		}
	      j = j + 1;
	    }
	  i = i + 1;
	}
      lim = lim - 1;
    }
  return (NULL);
}

char		**map_tab(const int fd)
{
  char		**tab;
  char		*buffer;
  int		lin;
  int		i;

  i = 0;
  lin = my_getnbr(get_next_line(fd));
  if ((tab = malloc(lin + 1 * sizeof(*tab))) == NULL)
    return (NULL);
  tab = my_tab_zero(tab, lin);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      tab[i] = my_strdup(buffer);
      i = i + 1;
    }
  return (tab);
}

/*
** life_check.c for game of life in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 14 19:41:04 2012 lyoma guillou
** Last update Mon May 14 22:55:07 2012 lyoma guillou
*/

#include <stdlib.h>

static int	_is_cell(char c)
{
  return ((c == '*'));
}

static int	is_alive(char **tab, int y, int x)
{
  int		cnt;
  int		j;
  int		i;

  cnt = 0;
  i = (x == 0) ? 0 : x - 1;
  j = (y == 0) ? 0 : y - 1;
  while (tab[i] && i <= x + 1)
    {
      j = (y == 0) ? 0 : y - 1;
      while (tab[i][j] && j <= x + 1)
	{
	  if (_is_cell(tab[i][j]) && (i != x || j != y))
	    ++cnt;
	  ++j;
	}
      ++i;
    }
  return ((cnt == 3) ? 1 : 0);
}

char		**check_cells(char **tab)
{
  int		i;
  int		j;
  int		live;

  i = 0;
  live = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (is_alive(tab, j, i))
	    {
	      tab[i][j] = '*';
	      live++;
	    }
	  else
	    tab[i][j] = ' ';
	  ++j;
	}
      ++i;
    }
  if (!live)
    return (NULL);
  return (tab);
}

/*
** create_tab.c for colles6 in /home/leduc_v//colles6
** 
** Made by victor leduc
** Login   <leduc_v@epitech.net>
** 
** Started on  Mon May 21 19:38:32 2012 victor leduc
** Last update Mon May 21 22:45:53 2012 lyoma guillou
*/

#include	<stdlib.h>
#include	"carre.h"

static void	_set_tab(t_elem *elem, int x, int y, t_pos *size)
{
  elem->color = 0;
  if (y % 2 == 0)
    {
      elem->size = (WIN_SIZE / size->x);
      elem->disp = 'h';
      elem->pos.x = (WIN_SIZE / size->x) +
	(x * (WIN_SIZE / size->x));
      elem->pos.y = y * WIN_SIZE / size->y;
    }
  else
    {
      elem->size = (WIN_SIZE / size->y);
      elem->disp = 'v';
      elem->pos.x = x * WIN_SIZE / size->x;
      elem->pos.y = (WIN_SIZE / size->y) +
	(y * (WIN_SIZE / size->y));
    }
}

t_elem		**create_tab(t_pos *size)
{
  t_elem	**tab;
  t_pos		val;

  tab = malloc(((size->x * 2) + 2) * sizeof(t_elem *));
  val.x = -1;
  while (++val.x <= (size->x * 2))
    tab[val.x] = malloc(((size->y * 2) + 2) * sizeof(t_elem));
  val.x = -1;
  while (++val.x <= (size->x * 2))
    {
      val.y = -1;
      while (++val.y <= (size->y * 2))
	{
	  if (((val.x % 2 == 1) && (val.y % 2 == 0)) ||
	      ((val.x % 2 == 0) && (val.y % 2 == 1)))
	    {
	      tab[val.x][val.y].exist = 0;
	      _set_tab(&tab[val.x][val.y], val.x, val.y, size);
	    }
	  else
	    tab[val.x][val.y].exist = 1;
	}
    }
  return (tab);
}

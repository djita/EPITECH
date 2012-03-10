/*
** grid_funcs.c for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 14:39:03 2011 lyoma guillou
** Last update Tue Dec 13 14:10:23 2011 lyoma guillou
*/

#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"

void		show_grid(void *ptr, void *win, t_grid *map)
{
  t_grid	*tmp;
  t_grid	*tmp2;

  tmp = map;
  tmp2 = map;
  while (tmp != NULL)
    {
      if (tmp->next != NULL && tmp->x <= tmp->next->x)
	draw_line(ptr, win, tmp, tmp->next);
      if (tmp2->x > tmp->x)
	{
	  draw_line(ptr, win, tmp2, tmp);
	  tmp2 = tmp2->next;
	  }
      tmp = tmp->next;
    }
}

t_grid		*projection(int x, int y, int z)
{
  t_grid	*dot;

  if ((dot = malloc(sizeof(*dot))) == NULL)
    return (NULL);
  dot->x = (CTE1 * x) - (CTE2 * y);
  dot->y = z + ((CTE1 / 2) * x) + ((CTE2 / 2) * y);
  return (dot);
}

t_grid		*grid_list(t_grid *first, t_grid *elem)
{
  t_grid	*tmp;

  tmp = first;
  if (NULL == tmp)
    return (elem);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  return (first);
}

t_grid		*grid_project(t_dot *data)
{
  t_dot		*tmp;
  t_grid	*list;
  t_grid	*elem;

  list = NULL;
  elem = NULL;
  tmp = data;
  while (tmp != NULL)
    {
      elem = projection(tmp->x, tmp->y, tmp->z);
      list = grid_list(list, elem);
      tmp = tmp->next;
    }
  return (list);
}

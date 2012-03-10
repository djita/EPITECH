/*
** projec_win.c for wolf3d in 
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 14:58:11 2012 lyoma guillou
** Last update Sat Jan 14 17:57:47 2012 lyoma guillou
*/

#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "map.h"

void		wall_collision(int **map, t_map *pos)
{
  
}

t_map		*scrn_init(t_scrn *win, t_map *pos)
{
  t_map		*dst;
  int		x_prim;
  int		y_prim;

  if ((dst = malloc(sizeof(*dst))) == NULL)
    return (NULL);
  dst->x = (double) D;
  dst->y = (double) ((P * ((win->win_x / 2) - pos->x)) / win->win_x);
  x_prim = (dst->x * cos(pos->angle)) - (dst->y * sin(pos->angle));
  y_prim = (dst->x * sin(pos->angle)) + (dst->y * cos(pos->angle));
  dst->x = x_prim + pos->x;
  dst->y = y_prim + pos->y;
  vec_x = dst->x - pos->x;
  vec_y = dst->y - pos->y;
  return (dst);
}

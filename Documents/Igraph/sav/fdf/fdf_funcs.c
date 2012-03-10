/*
** fdf_funcs.c for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 15:02:02 2011 lyoma guillou
** Last update Sun Dec 11 18:18:01 2011 lyoma guillou
*/

#include <mlx.h>
#include "fdf.h"

void		draw_line(void *ptr, void *win, t_grid *a, t_grid *b)
{
  t_draw	var;

  var.diff_x = ABS((b->x) - (a->x));
  var.diff_y = ABS((b->y) - (a->y));
  var.seg_x = ((a->x < b->x) ? (1) : (-1));
  var.seg_y = ((a->y < b->y) ? (1) : (-1));
  var.stroke = var.diff_x - var.diff_y;
  while (a->x != b->x || a->y != b->y)
    {
      mlx_pixel_put(ptr, win, POS_X - a->x, POS_Y - a->y, 0x00FFFFFF);
      var.stk2 = 2 * var.stroke;
      if (var.stk2 > -var.diff_y)
	{
	  var.stroke = var.stroke - var.diff_y;
	  a->x = a->x + var.seg_x;
	}
      if (var.stk2 < var.diff_x)
	{
	  var.stroke = var.stroke + var.diff_x;
	  a->y = a->y + var.seg_y;
	}
    }
}

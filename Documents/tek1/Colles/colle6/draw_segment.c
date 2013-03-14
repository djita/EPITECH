/*
** draw_segment.c for carre in /home/guillo_e//Documents/working/colles/colle6
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 19:43:51 2012 lyoma guillou
** Last update Mon May 21 21:43:51 2012 lyoma guillou
*/

#include <mlx.h>
#include "carre.h"

void		draw_vtcl(t_data *mlx, t_pos dpt, t_pos dst, int color)
{
  int		x;
  int		y;

  x = dpt.x;
  y = dpt.y;
  while (y != dst.y)
    {
      mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
      ++y;
    }
}

void		draw_hrzt(t_data *mlx, t_pos dpt, t_pos dst, int color)
{
  int		x;
  int		y;

  x = dpt.x;
  y = dpt.y;
  while (x != dst.x)
    {
      mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
      ++x;
    }
}

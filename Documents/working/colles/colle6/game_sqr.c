/*
** game_sqr.c for carre in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 21:10:03 2012 lyoma guillou
** Last update Mon May 21 22:59:01 2012 lyoma guillou
*/

#include "carre.h"

static t_pos	_show_square(t_data *mlx, t_pos *size)
{
  t_pos		dpt;
  t_pos		dst;
  t_pos		pad;

  dpt.y = 0;
  dst.x = mlx->size.x / size->x;
  dst.y = mlx->size.y / size->y;
  pad.x = dst.x;
  pad.y = dst.y;
  while (dpt.y <= mlx->size.y)
    {
      dpt.x = 0;
      while (dpt.x <= mlx->size.x)
	{
	  draw_vtcl(mlx, dpt, dst, WHITE);
	  draw_hrzt(mlx, dpt, dst, WHITE);
	  dpt.x = dpt.x + pad.x;
	  dst.x = dst.x + pad.x;
	}
      dpt.y = dpt.y + pad.y;
      dst.y = dst.y + pad.y;
    }
  return (pad);
}

void		game_init(t_data *mlx, t_pos *size)
{
  _show_square(mlx, size);
}

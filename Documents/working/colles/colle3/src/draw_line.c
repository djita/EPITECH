/*
** draw_line.c for draw_line in /home/deleta_m//Projets/Colles/Colle_3/src
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon Apr 30 20:43:01 2012 marc deletang
** Last update Mon Apr 30 22:03:26 2012 lyoma guillou
*/

#include "map.h"
#include "mlx.h"

void		aff_horizontal(t_map map, t_dot dep, t_dot arv, int turn)
{
  int		x;

  x = dep.x;
  while (x <= arv.x)
    {
      mlx_pixel_put(map.mlx, map.win, x, arv.y, turn);
      ++x;
    }
}

void		aff_vertical(t_map map, t_dot dep, t_dot arv, int turn)
{
  int		y;

  y = dep.y;
  while (y <= arv.y)
    {
      mlx_pixel_put(map.mlx, map.win, arv.x, y, turn);
      y++;
    }
}


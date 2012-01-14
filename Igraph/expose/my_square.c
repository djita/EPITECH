/*
** my_square.c for expose in /home/guillo_e//working/test/igraph/expose
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 11:08:23 2011 lyoma guillou
** Last update Wed Nov 16 11:12:45 2011 lyoma guillou
*/

#include <stdio.h>
#include <mlx.h>
#include "square.h"

void	my_square(t_square *sqr)
{
  int	x;
  int	y;

  x = 0;
  while (x <= sqr->size_x)
    {
      y = 0;
      while (y <= sqr->size_y)
	{
	  mlx_pixel_put(sqr->ptr, sqr->win, sqr->pos_x + x, sqr->pos_y + y, 0x00FF0000);
	  y++;
	}
      x++;
    }
  /*  printf("Final Pos: %d, %d\n", sqr->pos_x + x - 1, sqr->pos_y + y - 1); */
}

/*
** main.c for expose in /home/guillo_e//working/test/igraph/expose
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 11:05:07 2011 lyoma guillou
** Last update Thu Dec  8 17:42:12 2011 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "square.h"

int		my_key(int keycode, t_square *sqr)
{
  mlx_clear_window(sqr->ptr, sqr->win);
  //  printf("keycode = %d\n", keycode);
  if (65307 == keycode)
    {
      printf("Program exits\n");
      exit(EXIT_SUCCESS);
    }
  if (65361 == keycode || 113 == keycode) 
    sqr->pos_x -= 5;
  if (65362 == keycode || 122 == keycode)
    sqr->pos_y -= 5;
  if (65363 == keycode || 100 == keycode)
    sqr->pos_x += 5;
  if (65364 == keycode || 115 == keycode)
    sqr->pos_y += 5;
  my_square(sqr);
  return (1);
}

int		main(int ac, char **av)
{
  t_square	*square;

  square = malloc(sizeof(*square));
  if (NULL == square)
    return (0);
  square->ptr = mlx_init();
  square->win = mlx_new_window(square->ptr, 500, 500, "Expose");
  square->size_x = atoi(av[3]);
  square->size_y = atoi(av[4]);
  square->pos_x = atoi(av[1]) - square->size_x / 2;
  square->pos_y = atoi(av[2]) - square->size_y / 2;
  square->color = 0x00FF0000;

  mlx_key_hook(square->win, my_key, square);
  mlx_loop(square->ptr);
  return (0);
}

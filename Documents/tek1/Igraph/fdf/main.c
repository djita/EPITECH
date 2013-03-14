/*
** main.c for fdf in /home/guillo_e//working/test/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Nov  8 15:57:37 2011 lyoma guillou
** Last update Sun Dec 11 19:54:45 2011 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "get_next_line.h"
#include "fdf.h"

int		key_care(int keycode)
{
  if (65307 == keycode)
    {
      my_putstr("Exiting Program\n");
      exit(EXIT_SUCCESS);
    }
  return (1);
}

int		redraw(t_fdf *data)
{
  data->map = grid_project(map_elem(data->av[1]));
  mlx_clear_window(data->ptr,data->win);
  show_grid(data->ptr, data->win, data->map);
  return (1);
}

int		main(int ac, char **av)
{
  t_fdf		*data;

  if (ac == 2)
    {
      if ((data = malloc(sizeof(*data))) == NULL)
	return (-1);
      data->av = av;
      data->ptr = mlx_init();
      data->win = mlx_new_window(data->ptr, SIZE_X, SIZE_Y, "Fil de fer");
      data->map = grid_project(map_elem(av[1]));
      show_grid(data->ptr, data->win, data->map);
      mlx_key_hook(data->win, key_care, 0);
      mlx_expose_hook(data->win, redraw, data);
      mlx_loop(data->ptr);
    }
  return (0);
}

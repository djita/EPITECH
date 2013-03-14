/*
** my_graph.c for my_graph in /home/guillo_e//working/test/igraph/graph
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 27 18:13:00 2011 lyoma guillou
** Last update Thu Oct 27 20:49:54 2011 lyoma guillou
*/

#include <mlx.h>
#include <unistd.h>

int	main(int ac, char **av)
{
  void	*ptr;
  void	*win;
  int	x_max;
  int	y_max;

  x_max = 700;
  y_max = 700;
  ptr = mlx_init();
  win = mlx_new_window(ptr, x_max, y_max, "Graph");
  mlx_string_put(ptr, win, (x_max / 10), 25, 0x00FFFF, "LOADING...");
  graph(ptr, win, x_max, y_max);
  while (x_max > 0)
    {
      text(ptr, win, x_max, y_max);
      usleep(75000);
      mlx_clear_window(ptr, win);
      x_max = x_max - 50;
      y_max = y_max - 5;
      if (x_max < 10)
	x_max = 7000;
      if (y_max < 10)
	y_max = 700;
    }
}

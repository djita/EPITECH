/*
** shape_func.c for graph in /home/guillo_e//working/test/igraph/graph
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 27 18:25:43 2011 lyoma guillou
** Last update Sat Nov 12 19:13:57 2011 lyoma guillou
*/

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

int	text(void *ptr, void *win, int x_max, int y_max)
{
  int	color;
  int	color2;

  color = 0x00FF0000;
  color >>= 0;
  color2 = 0x0000FF00;
  printf("%p\n", color);
  printf("%p\n", color2);
  mlx_string_put(ptr, win, (x_max / 10), y_max - 25, color, "Here is your string in your ./Graph");
  mlx_string_put(ptr, win, (x_max / 10), y_max - 10, color2, "Et si tu veux encore du text tu peux continyuer d'appeler cette putin de fonction");
}

int	graph(void *ptr, void *window, int x_max, int y_max)
{
  int	x;
  int	y;
  int	border;

  border = 50;
  x = border;
  while (x < (x_max - border))
    {
      y = border;
      while (y < (y_max - border))
	{
	  mlx_pixel_put(ptr, window, x, y, 0x00FFFF);
	  y = y + 5;
	}
      usleep(25000);
      x = x + 5;
    }
  return (0);
}

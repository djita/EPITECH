/*
* my_pixel.c for igraph in /home/guillo_e//working/test/igraph
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 27 10:33:40 2011 lyoma guillou
** Last update Thu Nov 10 10:59:09 2011 lyoma guillou
*/

#include <mlx.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i])
    {
      res = res * 10;
      res = res + str[i] - '0';
      i++;
    }
  return (res);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int	main(int ac, char **av)
{
  void	*window;
  void	*ptr;
  int	x_max;
  int	y_max;
  int	nb;
  int	x;
  int	y;
  int	i;

  x_max = 500;
  y_max = 500;
  i = 0;
  ptr = mlx_init();
  window = mlx_new_window(ptr, x_max, y_max, "Window 1");
  if (ac == 2)
    nb = my_getnbr(av[1]);
  else
    nb = 100;
  while (i < nb)
    {
      x = x_max / 4;
      while (x < (3 * x_max) / 4)
	{
	  y = y_max / 4;
	  while (y < (3 * y_max) / 4 )
	    {
	      if ((i % 2) == 0)
		mlx_pixel_put(ptr, window, x, y, 0x00FF0000);
	      else if ((i % 3) == 0)
		mlx_pixel_put(ptr, window, x, y, 0x0000FF00);
	      else
		mlx_pixel_put(ptr, window, x, y, 0x000000FF);
	      y++;
	      //usleep(50);
	    }
	  x++;
	  //usleep(1000);
	  //	  mlx_clear_window(ptr, window);
	}
      i = i + 1;
      my_putnbr(i);
      my_putchar('\r');
    }
  while (42);
}

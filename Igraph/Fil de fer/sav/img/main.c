/*
** main.c for img in /home/guillo_e//working/igraph/img
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Dec  8 17:47:51 2011 lyoma guillou
** Last update Thu Dec  8 18:33:14 2011 lyoma guillou
*/

#include <stdio.h>
#include <mlx.h>

int	main()
{
  void	*ptr;
  void	*img;
  void	*win;
  char	*data;
  int	bpp;
  int	sizeline;
  int	endian;
  int	i;

  i = 0;
  ptr = mlx_init();
  win = mlx_new_window(ptr, 500, 500, "My New Window");
  img = mlx_new_image(ptr, 300, 300);
  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  while (data[i])
    {
      data[i] = 1;
      i++;
    }
  mlx_put_image_to_window(ptr, win, data, 20, 20);
  printf("Bpp: %d\nSizeline: %d\nEndian: %d\n", bpp, sizeline, endian);
  while (42);
}

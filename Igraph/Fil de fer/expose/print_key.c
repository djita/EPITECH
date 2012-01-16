/*
** print_key.c for print_key in /home/guillo_e//Documents/Igraph/expose
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 11:12:14 2012 lyoma guillou
** Last update Wed Jan 11 11:14:13 2012 lyoma guillou
*/

#include <stdio.h>
#include "mlx.h"

int		my_key(int keycode)
{
  printf("keycode = %d\n", keycode);
  if (65307 == keycode)
    {
      printf("Program exits\n");
      exit(EXIT_SUCCESS);
    }
  return (1);
}

int		main()
{
  void		*ptr;
  void		*win;

  ptr = mlx_init();
  win = mlx_new_window(ptr, 100, 100, "New Window");
  mlx_key_hook(win, my_key, 0);
  mlx_looop(ptr);
  return (0);
}

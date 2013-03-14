/*
** main.c for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 10:01:55 2012 lyoma guillou
** Last update Sat Jan 14 17:30:46 2012 lyoma guillou
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "key.h"
#include "map.h"

int             key_care(int keycode)
{
  if (ESCK == keycode)
    {
      printf("Exiting Program\n");
      exit(EXIT_SUCCESS);
    }
  if ((arrow_keys(keycode)))
    printf("you've pressed an arrow key\n");
  return (1);
}

int		main()
{
  t_scrn	*scn;
  void		*sky;
  void		*grd;
  int		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		i;

  if ((scn = malloc(sizeof(*scn))) == NULL)
    return (-1);
  scn->ptr = mlx_init();
  scn->win = mlx_new_window(scn->ptr, 800, 600, "New window");
  sky = mlx_new_image(scn->ptr, 800, 600 / 2);
  grd = mlx_new_image(scn->ptr, 800, 600 / 2);
  data = (int *) mlx_get_data_addr(sky, &bpp, &sizeline, &endian);
  i = 0;
  while (i < (800 * (600 / 2)))
    data[i++] = 0x66FF77;
  i = 0;
  data = (int *) mlx_get_data_addr(grd, &bpp, &sizeline, &endian);
  while (i < (800 * (600 / 2)))
    data[i++] = 0x99FF33;
  mlx_put_image_to_window(scn->ptr, scn->win, sky, 0, (600 / 2));
  mlx_put_image_to_window(scn->ptr, scn->win, grd, 0, 0);
  mlx_key_hook(scn->win, key_care, 0);
  mlx_loop(scn->ptr);
  return (0);
}

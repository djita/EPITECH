/*
** main.c for carre in /home/guillo_e//Documents/working/colles/colle3
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 19:35:38 2012 lyoma guillou
** Last update Mon Apr 30 22:38:31 2012 lyoma guillou
*/

#include <mlx.h>
#include "map.h"

void		aff_terrain(t_map data, int turn)
{
  t_dot		dep;
  t_dot		arv;

  dep.x = 0;
  dep.y = 0;
  arv.x = 0;
  arv.y = data.win_y;
  while (dep.x <= data.win_x)
    {
      aff_vertical(data, dep, arv, turn);
      dep.x = dep.x + data.win_x / data.w;
      arv.x = dep.x;
    }
  dep.x = 0;
  dep.y = 0;
  arv.x = data.win_x;
  arv.y = 0;
  while (dep.y <= data.win_y)
    {
      aff_horizontal(data, dep, arv, turn);
      dep.y = dep.y + data.win_y / data.h;
      arv.y = dep.y;
    }
}

t_map		get_map(t_map data, char **av)
{
  int		i;

  i = 1;
  data.w = 10;
  data.h = 10;
  while (av[i])
    {
      if (!my_strcmp(av[i], "-l") && av[i + 1])
	data.w = my_getnbr(av[i + 1]);
      else if (!my_strcmp(av[i], "-L") && av[i + 1])
	data.h = my_getnbr(av[i + 1]);
      ++i;
    }
  return (data);
}

void		the_game(t_map data)
{
  t_game	turn;

  turn.p1 = 0x00FF0000;
  turn.p2 = 0x0033CC00;
  turn.dep.x = 0;
  turn.dep.y = 0;
  turn.arv.x = 0;
  turn.arv.y = data.win_y / data.h;
  aff_vertical(data, turn.dep, turn.arv, turn.p1);
  mlx_key_hook(data.win, key_handle, &turn);
}

int		main(int ac, char **av)
{
  t_map		data;

  if (ac)
    {
      data.mlx = mlx_init();
      data = get_map(data, av);
      data.win_x = 750;
      data.win_y = 750;
      data.win = mlx_new_window(data.mlx, data.win_x + 1, data.win_y + 1, "Carre");
      aff_terrain(data, WHITE);
      the_game(data);
      mlx_loop(data.mlx);
    }
  return (0);
}

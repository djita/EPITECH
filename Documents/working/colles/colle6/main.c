/*
** main.c for carre in /home/guillo_e//Documents/working/colles/colle6
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 19:17:06 2012 lyoma guillou
** Last update Mon May 21 22:59:13 2012 lyoma guillou
*/

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "carre.h"
#include "utils.h"

int		key_handler(int keycode, t_game *game)
{
  game->flag = keycode;
  if (keycode == ESC)
    exit(EXIT_SUCCESS);
  if (keycode == LEFT || keycode == UP || keycode == RIGHT
      || keycode == DOWN || keycode == SPACE)
    move(game);
  return (keycode);
}

t_data		*init_data()
{
  t_data	*mlx;

  mlx = xmalloc(sizeof(*mlx));
  mlx->size.x = 501;
  mlx->size.y = 501;
  mlx->ptr = mlx_init();
  mlx->win = mlx_new_window(mlx->ptr, mlx->size.x, mlx->size.y, "Carre");
  return (mlx);
}

int		main(int ac, char **av)
{
  t_game	*hand;
  t_pos		*sqr;

  if (ac)
    {
      hand = xmalloc(sizeof(*hand));
      sqr = xmalloc(sizeof(*sqr));
      hand->mlx = init_data();
      hand->pls = xmalloc(sizeof(*hand->pls));
      hand->sqr = xmalloc(sizeof(*hand->sqr));
      init_argv(&hand->pls, sqr, av);
      hand->sqr = sqr;
      hand->mem = create_tab(hand->sqr);
      game_init(hand->mlx, hand->sqr);
      mlx_key_hook(hand->mlx->win, &key_handler, hand);
      mlx_loop(hand->mlx->ptr);
    }
  return (0);
}

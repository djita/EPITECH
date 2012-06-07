/*
** move.c for move in /u/all/guillo_e/public/deleta_m
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 21 22:03:39 2012 marc deletang
** Last update Mon May 21 22:58:38 2012 lyoma guillou
*/

#include	"carre.h"

void		move(t_game *game)
{
  static int	x = 0;
  static int	y = 1;

  if (game->flag == LEFT)
    {
      if (x > 1)
	x -= 2;
    }
  else if (game->flag == RIGHT)
    {
      if (x < game->sqr->x - 1)
	x += 2;
    }
  else if (game->flag == UP)
    {
      if (y > 1)
	y -= 2;
    }
  else if (game->flag == DOWN)
    {
      if (x < game->sqr->y - 1)
	y += 2;
    }
}

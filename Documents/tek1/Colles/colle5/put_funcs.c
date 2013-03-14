/*
** put_funcs.c for game of life in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 14 19:28:02 2012 lyoma guillou
** Last update Mon May 14 22:28:44 2012 lyoma guillou
*/

#include <unistd.h>

#include "game_of_life.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  write(1, str, i);
}

static void	show_border(int x)
{
  int		j;

  j = 0;
  my_putchar('+');
  while (j++ < x)
    my_putchar('-');
  my_putchar('+');
  my_putchar('\n');
}

void		my_putxmap(char **tab, int y, int x)
{
  int		i;
  int		j;

  i = 0;
  (void) y;
  show_border(x);
  while (tab[i])
    {
      j = 0;
      my_putchar('|');
      while (tab[i][j])
	{
	  my_putchar(tab[i][j]);
	  ++j;
	}
      my_putchar('|');
      my_putchar('\n');
      ++i;
    }
  show_border(x);
}

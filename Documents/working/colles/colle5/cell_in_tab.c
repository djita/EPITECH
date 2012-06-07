/*
** cell_in_tab.c for cell_in_tab in /home/deleta_m//Projets/Colles/Colle_5
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 20:38:28 2012 marc deletang
** Last update Mon May 14 22:54:40 2012 lyoma guillou
*/

#include <stdlib.h>
#include "game_of_life.h"

static char	**init_tab(char **tab, int x, int y)
{
  int	pos_x;
  int	pos_y;

  pos_y = 0;
  while (pos_y != y)
    {
      pos_x = 0;
      while (pos_x != x)
	{
	  tab[pos_y][pos_x] = ' ';
	  pos_x++;
	}
      pos_y++;
    }
  return (tab);
}

char	**cell_in_tab(char **tab, int x, int y, int cell)
{
  int	i;
  int	pos_x;
  int	pos_y;

  i = 0;
  tab = init_tab(tab, x, y);
  pos_x = generate_rand(x);
  pos_y = generate_rand(y);
  while (i != cell)
    if (tab[pos_y][pos_x] != '*')
      {
	tab[pos_y][pos_x] = '*';
	pos_y = rand() % 7;
	pos_x = rand() % 7;
	i++;
      }
  return (tab);
}

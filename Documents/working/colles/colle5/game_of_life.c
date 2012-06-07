/*
** game_of_life.c for game_of_life in /home/deleta_m//Projets/Colles/Colle_5
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 19:15:08 2012 marc deletang
** Last update Mon May 14 22:55:45 2012 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>
#include "game_of_life.h"

char 	**create_game(int x, int y)
{
  int	y_tab;
  char	**tab;

  y_tab = 0;
  tab = xmalloc((y + 1) * sizeof(*tab));
  my_bzero(tab, y);
  while (y_tab < y)
    {
      tab[y_tab] = xmalloc((x + 1) * sizeof(**tab));
      my_bzero(tab[y_tab], x);
      y_tab++;
    }
  return (tab);
}

int	read_it()
{
  int	it;
  int	ret;
  char	*buff;

  buff = NULL;
  my_putstr("Entrez le nombre d'itérations:...\n");
  buff = xmalloc(100);
  my_bzero(buff, 100);
  ret = xread(0, buff, 99);
  it = my_getnbr(buff);
  return (it);
}


void	game_of_life(int x, int y, int cell)
{
  char	**tab;
  int	it;

  tab = create_game(x, y);
  tab = cell_in_tab(tab, x, y, cell);
  my_putxmap(tab, y, x);
  while ((it = read_it()))
    while (it > 0)
      {
	tab = check_cells(tab);
	if (!tab)
	  {
	    my_putstr("No more cells alive\n");
	    return;
	  }
	my_putxmap(tab, y, x);
	sleep(1);
	--it;
      }
}

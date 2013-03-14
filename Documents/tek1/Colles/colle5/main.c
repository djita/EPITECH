/*
** main.c for main in /home/deleta_m//Projets/Colles/Colle_5
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 19:05:30 2012 marc deletang
** Last update Mon May 14 22:38:44 2012 lyoma guillou
*/

#include "game_of_life.h"

int		main(int ac, char **av)
{
  int		width;
  int		height;
  int		cell;

  if (ac != 4)
    {
      my_putstr("Usage:");
      my_putstr(av[0]);
      my_putstr(" [y] [x] [cells]\n");
      return (-1);
    }
  else
    {
      width = my_getnbr(av[1]);
      height = my_getnbr(av[2]);
      cell = my_getnbr(av[3]);
      if (!width || !height || !cell || width * height < cell)
	{
	  my_putstr("Arguments: are in bad format\n");
	  return (-1);
	}
      game_of_life(my_getnbr(av[1]), my_getnbr(av[2]), my_getnbr(av[3]));
    }
  return (0);
}


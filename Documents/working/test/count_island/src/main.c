/*
** main.c for count_island in /home/guillo_e//Documents/working/test/count_island
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 21:50:46 2012 lyoma guillou
** Last update Sat Mar 10 21:51:05 2012 lyoma guillou
*/

#include <cnt_isl.h>

int		main(int ac, char **av)
{
  if (ac == 2)
    count_island(av[1]);
  else
    my_putchar('\n');
  return (0);
}

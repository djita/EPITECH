/*
** main.c for my_printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 16:01:51 2011 lyoma guillou
** Last update Fri Nov 25 17:16:34 2011 lyoma guillou
*/

#include <stdio.h>
#include "my_printf.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
  int		num;

  num = 0;
  if (ac == 1)
    return (0);
  num = my_printf("Voici le pointeur du premier argument: %p, et voici le binaire du 2ème: %b\n", av[1], my_getnbr(av[1]));
  printf("Voici le pointeur du premier argument: %p, et voici le binaire du 2ème:\n", av[1]);
  my_putchar('\n');
  return (0);
}

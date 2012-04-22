/*
** fprime.c for fprime in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr  7 10:41:25 2012 exam_user
** Last update Sat Apr  7 11:52:08 2012 exam_user
*/

#include <stdio.h>
#include <stdlib.h>

void		fprime(int nb)
{
  int		prim;

  prim = 2;
  if (nb <= 1 && nb >= 0)
    {
      printf("%i", nb);
      return;
    }
  while (nb != 1)
    {
      while ((nb % prim) == 0)
	{
	  nb = nb / prim;
	  printf("%i", prim);
	  printf(nb != 1 ? "*" : "");
	}
      ++prim;
    }
}

int		main(int ac, char **av)
{
  if (ac >= 2)
    fprime(atoi(av[1]));
  printf("\n");
  return (0);
}

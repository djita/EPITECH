/*
** main.c for getnextline in /home/guillo_e//Documents/Prog Elem/get_next_line
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Nov 25 13:53:50 2011 lyoma guillou
** Last update Mon Nov 28 17:12:26 2011 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main()
{
  char	*s;

  while ((s = get_next_line(0)))
    {
      printf("%s\n", s);
      free(s);
    }
  return (0);
}

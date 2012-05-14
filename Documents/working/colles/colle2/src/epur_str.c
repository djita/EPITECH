/*
** epur_str.c for epur_str in /home/deleta_m//Projets/Colles/Colle_2
**
** Made by marc deletang
** Login   <deleta_m@epitech.net>
**
** Started on  Tue Apr 24 21:08:56 2012 marc deletang
** Last update Tue Apr 24 22:45:23 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

char 	*epur_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] <= ' ' && str[i])
    i++;
  my_strcpy(str, str + i);
  return (str);
}

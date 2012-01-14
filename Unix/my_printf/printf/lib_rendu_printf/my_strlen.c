/*
** my_strlen.c for my_strlen in /home/guillo_e//afs/rendu/piscine/Jour_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct  6 09:06:06 2011 lyoma guillou
** Last update Wed Nov 16 14:35:47 2011 lyoma guillou
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

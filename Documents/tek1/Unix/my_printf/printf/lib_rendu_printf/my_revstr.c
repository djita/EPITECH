/*
** my_revstr.c for my_revstr in /home/guillo_e//afs/rendu/piscine/Jour_06
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 12 14:59:27 2010 lyoma guillou
** Last update Wed Nov 16 14:35:49 2011 lyoma guillou
*/

#include "my.h"

char	*my_revstr(char *str)
{
  char	c;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[j])
    j++;
  j = j - 1;
  while (i < j)
    {
      c = str[j];
      str[j] = str[i];
      str[i] = c;
      i++;
      j--;
    }
  return (str);
}

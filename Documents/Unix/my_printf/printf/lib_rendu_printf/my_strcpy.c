/*
** my_strcpy.c for my_strcpy in /home/guillo_e//afs/rendu/piscine/Jour_06
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 11 20:33:02 2010 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return(dest);
}

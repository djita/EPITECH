/*
** my_strcat.c for my_strcat in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 09:17:29 2011 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (dest[len])
    len++;
  while (src[i])
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
}

/*
** my_strfuncs.c for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 10:13:57 2012 lyoma guillou
** Last update Sat Jan 14 17:27:07 2012 lyoma guillou
*/

#include "get_next_line.h"
#include "map.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i++]);
  return (i);
}

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i++;
    }
  dst[i] = '\0';
  return (dst);
}

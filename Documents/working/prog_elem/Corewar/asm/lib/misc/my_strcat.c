/*
** my_strcat.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 17:47:28 2012 louis duverdier
** Last update Fri Jan 20 10:43:02 2012 louis duverdier
*/

#include <my.h>

char	*my_strcat(char *dest, const char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}

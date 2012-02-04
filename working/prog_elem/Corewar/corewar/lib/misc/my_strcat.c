/*
** my_strcat.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:22 2012 louis duverdier
*/

#include <my.h>

char	*my_strcat(char *dest, const char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}

/*
** my_strcat.c for misc in /home/czegan_g/project/current/corewar/asm/lib/misc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 19 17:47:28 2012 louis duverdier
** Last update ven. mars 23 00:34:54 2012 gaby czegany
*/

# include       <my.h>

char	*my_strcat(char *dest, const char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}

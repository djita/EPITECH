/*
** my_strcpy.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:13 2012 louis duverdier
*/

char	*my_strcpy(char *dest, const char *src)
{
  char	*ret;

  ret = dest;
  while (*src)
    {
      *dest = *src++;
      ++dest;
    }
  *dest = '\0';
  return (ret);
}

char	*my_strncpy(char *dest, const char *src, int len)
{
  int	i;

  i = 0;
  while (*src && i < len)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

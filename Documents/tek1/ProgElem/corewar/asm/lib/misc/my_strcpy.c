/*
** my_strcpy.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 17:45:18 2012 louis duverdier
** Last update Fri Jan 20 11:58:57 2012 louis duverdier
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

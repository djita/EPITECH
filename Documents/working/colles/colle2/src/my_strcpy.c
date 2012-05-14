/*
** my_strcpy.c for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:47:21 2012 lyoma guillou
** Last update Tue Apr 24 20:14:47 2012 lyoma guillou
*/

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strncpy(char *dst, char *src, int len)
{
  int		i;

  i = 0;
  while (src[i] && i < len)
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

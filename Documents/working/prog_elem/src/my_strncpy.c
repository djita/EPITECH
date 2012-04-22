/*
** my_strncpy.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Apr  5 16:02:26 2012 lyoma guillou
** Last update Thu Apr  5 16:04:04 2012 lyoma guillou
*/

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

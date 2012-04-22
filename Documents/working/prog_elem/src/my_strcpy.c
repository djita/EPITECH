/*
** my_strcpy.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Apr  5 16:03:38 2012 lyoma guillou
** Last update Thu Apr  5 16:03:50 2012 lyoma guillou
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
  dst[i] = 0;
  return (dst);
}

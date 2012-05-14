/*
** my_strcmp.c for  in /home/guillo_e//Documents/working/colles/colle3/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 20:59:20 2012 lyoma guillou
** Last update Mon Apr 30 20:59:33 2012 lyoma guillou
*/

int		my_strcmp(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i] && dst[i] && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

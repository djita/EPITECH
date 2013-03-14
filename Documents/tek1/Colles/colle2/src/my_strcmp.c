/*
** my_strcmp.c for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:46:53 2012 lyoma guillou
** Last update Tue Apr 24 20:14:47 2012 lyoma guillou
*/

int		my_strcmp(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i] && dst[i] && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

int		my_strncmp(char *src, char *dst, int len)
{
  int		i;

  i = 0;
  while (src[i] && dst[i] && i < len && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

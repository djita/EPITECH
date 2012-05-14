/*
** my_memset.c for reader in /home/guillo_e//Documents/working/colles/colle2/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 20:02:02 2012 lyoma guillou
** Last update Tue Apr 24 20:14:48 2012 lyoma guillou
*/

void		*my_memset(void *ptr, int c, int len)
{
  int		*buf;
  int		i;

  i = 0;
  buf = ptr;
  while (i < len)
    {
      buf[i] = c;
      ++i;
    }
  return (ptr);
}

/*
** my_memset.c for misc in /home/czegan_g/project/current/corewar/asm/lib/misc
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. janv. 31 06:56:56 2012 gaby czegany
** Last update mar. févr. 14 08:14:43 2012 gaby czegany
*/

void    *my_memset(void *s, int c, int n)
{
  int           i;
  char          *cast;

  cast = (char *) s;
  i = 0;
  while (i < n)
  {
    *cast = c;
    ++cast;
    ++i;
  }
  return (s);
}


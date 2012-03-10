/*
** my_memcpy.c for misc in /home/czegan_g/project/current/corewar/asm/lib/misc
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. janv. 31 07:14:42 2012 gaby czegany
** Last update mar. févr. 14 08:14:41 2012 gaby czegany
*/

void    *my_memcpy(void *dst, void *src, int len)
{
  int   i;
  char  *cast_src;
  char  *cast_dst;

  cast_src = (char *) src;
  cast_dst = (char *) dst;
  i = 0;
  while (i < len)
  {
    *cast_dst = *cast_src;
    cast_src++;
    cast_dst++;
    i = i + 1;
  }
  return (dst);
}


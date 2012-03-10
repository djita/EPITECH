/*
** free_funcs.c for filler_baby in /home/guillo_e//Documents/working/rush/filler_baby
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Feb 26 01:22:41 2012 lyoma guillou
** Last update Sun Feb 26 01:42:40 2012 lyoma guillou
*/

#include <filler.h>

void		struct_free(t_vm to_free)
{
  int		i;

  i = 0;
  while (to_free.map[i])
    free(to_free.map[i++]);
  free(to_free.map);
  i = 0;
  while (to_free.pxc[i])
    free(to_free.pxc[i++]);
  free(to_free.pxc);
}

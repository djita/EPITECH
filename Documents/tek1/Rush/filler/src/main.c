/*
** main.c for filler_baby in /home/jacque_i/Documents/Projet/B2/cpe-rush2-2016-guillo_e/filler_baby
** 
** Made by allan jacquet-cretides
** Login   <jacque_i@epitech.net>
** 
** Started on  Sat Feb 25 17:59:51 2012 allan jacquet-cretides
** Last update Mon Feb 27 08:08:16 2012 lyoma guillou
*/

#include <filler.h>

int		main()
{
  t_vm		mp_h;
  t_pos		slot;
  char		*str;
  char		*trash;
  int		i;

  i = 0;
  while (42)
    {
      mp_h.map = get_map();
      mp_h.pxc = get_piece();
      str = xmalloc(OUT_SIZE);
      trash = xmalloc(OUT_SIZE);
      slot = get_valid_pos(mp_h);
      sprintf(str, "%i %i\n", slot.y, slot.x);
      bzero(trash, OUT_SIZE);
      while (strcmp(trash, "Position O?"))
	scanf(" %[^\n]", trash);
      free(trash);
      xwrite(1, str, strlen(str));
      free(str);
      struct_free(mp_h);
    }
  return (0);
}

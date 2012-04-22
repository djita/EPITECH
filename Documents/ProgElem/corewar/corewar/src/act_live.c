/*
** act_live.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Mar 13 12:36:04 2012 louis duverdier
** Last update Sat Mar 24 16:13:48 2012 louis duverdier
*/

#include "corewar.h"

void		act_live(t_handler *h, t_process *p)
{
  int		id;
  t_node	*node;
  t_champ	*champ;

  id = data_int(h, p->pc + 1, DIR_SIZE);
  node = h->champ_list->first;
  while (node)
    {
      champ = node->data;
      if (champ->champ_id == id)
        {
          champ->last_live = h->current_cycle;
          my_putstr("Le joueur ");
          my_putnbr(id);
          my_putstr(" (");
          my_putstr(champ->name);
          my_putstr(") est en vie.\n");
          node = NULL;
        }
      else
        node = node->next;
    }
  p->pc = (p->pc + 1 + DIR_SIZE) % MEM_SIZE;
}

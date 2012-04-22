/*
** init.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Mar 14 09:52:55 2012 louis duverdier
** Last update Sat Mar 24 13:41:31 2012 louis duverdier
*/

#include "corewar.h"

static void	_fill(t_handler *h,
                      void (*fnc)(t_handler *, t_process *),
                      int pos)
{
  static int	end = 0;

  h->act_ptr[pos].code = end ? 0 : op_tab[pos].code;
  h->act_ptr[pos].fnc = end ? NULL : fnc;
  if (op_tab[pos].mnemonique == 0)
    end = 1;
}

void	init_ptr(t_handler *h)
{
  h->act_ptr = xmalloc((MAX_ACTIONS + 1) * sizeof(*(h->act_ptr)));
  _fill(h, &act_live, 0);
  _fill(h, &act_ld, 1);
  _fill(h, &act_st, 2);
  _fill(h, &act_add, 3);
  _fill(h, &act_sub, 4);
  _fill(h, &act_and, 5);
  _fill(h, &act_or, 6);
  _fill(h, &act_xor, 7);
  _fill(h, &act_jmp, 8);
  _fill(h, &act_ldi, 9);
  _fill(h, &act_sti, 10);
  _fill(h, &act_fork, 11);
  _fill(h, &act_lld, 12);
  _fill(h, &act_lldi, 13);
  _fill(h, &act_lfork, 14);
  _fill(h, &act_aff, 15);
  _fill(h, NULL, 16);
}

t_champ		*create_champ(int id, int address)
{
  t_champ	*champ;

  champ = xmalloc(sizeof(*champ));
  champ->alive = 1;
  champ->champ_id = id > 0 ? id : -1;
  champ->name = NULL;
  champ->comment = NULL;
  champ->last_live = 0;
  champ->mem_pos = address >= 0 ? address % MEM_SIZE : -1;
  champ->process_list = list_create();
  return (champ);
}

t_process	*create_process(t_champ *champ)
{
  int		tmp;
  t_process	*process;

  process = xmalloc(sizeof(*process));
  process->pc = champ->mem_pos;
  process->next_action = 0;
  process->carry = 0;
  process->champ = champ;
  process->exec_cycle = 0;
  process->act = NULL;
  tmp = 0;
  while (tmp <= REG_NUMBER)
    {
      process->reg[tmp] = 0;
      ++tmp;
    }
  process->reg[0] = champ->champ_id;
  return (process);
}

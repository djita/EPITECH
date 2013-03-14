/*
** act_fork.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Wed Mar 14 17:44:27 2012 gaelle fouasse
** Last update Sat Mar 24 16:13:24 2012 louis duverdier
*/

#include "corewar.h"

static void	_fill_reg(t_process *dest, t_process *src)
{
  int		tmp;

  tmp = 0;
  while (tmp < REG_NUMBER)
    {
      dest->reg[tmp] = src->reg[tmp];
      ++tmp;
    }
}

static void	_act(t_handler *h, t_process *p, int type)
{
  t_process	*process;

  process = xmalloc(sizeof(*process));
  process->champ = p->champ;
  _fill_reg(process, p);
  if (type)
    {
      process->pc = (p->pc + (data_int(h, p->pc + 1, IND_SIZE) % IDX_MOD));
      process->pc %= MEM_SIZE;
    }
  else
    process->pc = (p->pc + data_int(h, p->pc + 1, IND_SIZE)) % MEM_SIZE;
  process->carry = p->carry;
  process->next_action = p->next_action;
  process->exec_cycle = 0;
  process->act = NULL;
  list_append(p->champ->process_list, node_create_from(process));
  if (!type)
    p->carry = 1;
  p->pc = (p->pc + 1 + IND_SIZE) % MEM_SIZE;
}

void	act_fork(t_handler *h, t_process *p)
{
  _act(h, p, 1);
}

void    act_lfork(t_handler *h, t_process *p)
{
  _act(h, p, 0);
}

/*
** act_op.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Thu Mar 15 15:31:44 2012 gaelle fouasse
** Last update Sat Mar 24 16:14:18 2012 louis duverdier
*/

#include "corewar.h"

static void	_act(t_handler *h, t_process *p, int type)
{
  int	r1;
  int	r2;
  int	r3;

  r1 = data_int(h, p->pc + 2, 1);
  r2 = data_int(h, p->pc + 3, 1);
  r3 = data_int(h, p->pc + 4, 1);
  if (reg_valid(r1) && reg_valid(r2) && reg_valid(r3))
    {
      if (type)
        p->reg[r3 - 1] = p->reg[r1 - 1] + p->reg[r2 - 1];
      else
        p->reg[r3 - 1] = p->reg[r1 - 1] - p->reg[r2 - 1];
      p->carry = 1;
    }
  else
    p->carry = 0;
  p->pc = (p->pc + 5) % MEM_SIZE;
}

void	act_add(t_handler *h, t_process *p)
{
  _act(h, p, 1);
}

void	act_sub(t_handler *h, t_process *p)
{
  _act(h, p, 0);
}

/*
** act_loadi.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Wed Mar 21 15:40:49 2012 gaelle fouasse
** Last update Sat Mar 24 16:35:12 2012 louis duverdier
*/

#include "corewar.h"

static void	_act(t_handler *h, t_process *p, int type)
{
  t_data	d;
  int		p1;
  int		p2;
  int		p3;

  d.h = h;
  d.p = p;
  d.valid = 1;
  d.index = 1;
  d.offset = 2;
  d.size = IND_SIZE;
  d.descr = data_int(h, p->pc + 1, 1);
  get_value(&d, &p1, 1, type);
  get_value(&d, &p2, 2, type);
  p3 = data_int(h, p->pc + d.offset, 1);
  p->carry = 0;
  if (d.valid && reg_valid(p3))
    {
      p->reg[p3 - 1] = data_int(h, p1 + p2, REG_SIZE);
      p->carry = 1;
    }
  p->pc = (p->pc + d.offset + 1) % MEM_SIZE;
}

void	act_ldi(t_handler *h, t_process *p)
{
  _act(h, p, 1);
}

void	act_lldi(t_handler *h, t_process *p)
{
  _act(h, p, 0);
}

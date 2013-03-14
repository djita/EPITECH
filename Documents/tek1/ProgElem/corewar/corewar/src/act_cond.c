/*
** act_cond.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Mon Mar 19 11:57:17 2012 gaelle fouasse
** Last update Sat Mar 24 16:36:58 2012 louis duverdier
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
  d.index = 0;
  d.offset = 2;
  d.size = IND_SIZE;
  d.descr = data_int(h, p->pc + 1, 1);
  get_value(&d, &p1, 1, 1);
  get_value(&d, &p2, 2, 1);
  p3 = data_int(h, p->pc + d.offset, 1);
  p->carry = 0;
  if (d.valid && reg_valid(p3))
    {
      p->reg[p3 - 1] = type == 1 ? p1 & p2 : type == 2 ? p1 | p2 : p1 ^ p2;
      p->carry = 1;
    }
  p->pc = (p->pc + d.offset + 1) % MEM_SIZE;
}

void	act_and(t_handler *h, t_process *p)
{
  _act(h, p, 1);
}

void	act_or(t_handler *h, t_process *p)
{
  _act(h, p, 2);
}

void	act_xor(t_handler *h, t_process *p)
{
  _act(h, p, 3);
}

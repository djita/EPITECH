/*
** act_store.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Sat Mar 24 16:43:10 2012 louis duverdier
** Last update Sat Mar 24 16:47:01 2012 louis duverdier
*/

/*
** store.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Wed Mar 21 14:39:52 2012 gaelle fouasse

*/

#include "corewar.h"

static void	_fill(char *buff, int value)
{
  int		i;

  i = 0;
  while (i < REG_SIZE)
    {
      buff[REG_SIZE - i - 1] = value % 10;
      value /= 10;
      ++i;
    }
}

void	act_st(t_handler *h, t_process *p)
{
  int	p1;
  int	p2;
  int	descr;
  char	buff[REG_SIZE];

  descr = data_int(h, p->pc + 1, 1);
  p1 = data_int(h, p->pc + 2, 1);
  if (get_type(descr, 2) == T_REG && reg_valid(p1))
    {
      p2 = data_int(h, p->pc + 3, 1);
      if (reg_valid(p2))
        p->reg[p2 - 1] = p->reg[p1 - 1];
      p->pc = (p->pc + 4) % MEM_SIZE;
    }
  else if (reg_valid(p1))
    {
      p2 = data_int(h, p->pc + 3, IND_SIZE);
      _fill(buff, p->reg[p1 - 1]);
      insert(h, buff, p->pc + p2 % IDX_MOD, REG_SIZE);
      p->pc = (p->pc + 3 + IND_SIZE) % MEM_SIZE;
    }
}

void		act_sti(t_handler *h, t_process *p)
{
  t_data	d;
  int		p1;
  int		p2;
  int		p3;
  char		buff[REG_SIZE];

  d.h = h;
  d.p = p;
  d.valid = 1;
  d.index = 1;
  d.offset = 3;
  d.size = REG_SIZE;
  d.descr = data_int(h, p->pc + 1, 1);
  p1 = data_int(h, p->pc + 2, 1);
  get_value(&d, &p2, 2, 1);
  get_value(&d, &p3, 3, 1);
  if (d.valid && reg_valid(p1))
    {
      _fill(buff, p->reg[p1 - 1]);
      insert(h, buff, p->pc + p2 + p3, REG_SIZE);
    }
  p->pc = (p->pc + d.offset) % MEM_SIZE;
}

/*
** act_aff.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Wed Mar 14 16:52:28 2012 gaelle fouasse
** Last update Sat Mar 24 16:24:57 2012 louis duverdier
*/

#include "corewar.h"

void    act_aff(t_handler *h, t_process *p)
{
  int	reg;

  reg = data_int(h, p->pc + 2, 1);
  if (reg_valid(reg))
    my_putchar(p->reg[reg - 1] % 256);
  p->pc = (p->pc + 3) % MEM_SIZE;
}

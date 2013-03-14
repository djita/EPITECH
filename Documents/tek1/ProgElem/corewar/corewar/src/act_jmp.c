/*
** act_jmp.c for corewar in /home/fouass_g//Cod/corewar/corewar/src
** 
** Made by gaelle fouasse
** Login   <fouass_g@epitech.net>
** 
** Started on  Wed Mar 14 16:04:23 2012 gaelle fouasse
** Last update Sat Mar 24 16:12:32 2012 louis duverdier
*/

#include "corewar.h"

void	act_jmp(t_handler *h, t_process *p)
{
  if (p->carry)
    p->pc = (p->pc + data_int(h, p->pc + 1, IND_SIZE) % IDX_MOD) % MEM_SIZE;
}

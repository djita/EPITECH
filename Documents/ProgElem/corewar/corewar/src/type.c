/*
** type.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Mon Mar 19 11:47:24 2012 louis duverdier
** Last update Sat Mar 24 16:29:56 2012 louis duverdier
*/

#include "corewar.h"

static int	_size_for_type(t_data *d)
{
  if (d->type == T_REG)
    return (1);
  if (d->type == T_DIR && d->index)
    return (IND_SIZE);
  if (d->type == T_DIR)
    return (DIR_SIZE);
  if (d->type == T_IND)
    return (IND_SIZE);
  return (0);
}

void	get_value(t_data *d, int *value, int pos, int idx)
{
  if (d->valid)
    {
      d->type = get_type(d->descr, pos);
      *value = data_int(d->h, d->p->pc + d->offset, _size_for_type(d));
      if (d->type == T_REG)
        {
          d->valid = d->valid && reg_valid(*value);
          if (d->valid)
            *value = d->p->reg[*value - 1];
        }
      else if (d->type == T_IND)
        {
          *value = idx ? *value % IDX_MOD : *value;
          *value = data_int(d->h, d->p->pc + *value, REG_SIZE);
        }
      else if (d->type != T_DIR)
        d->valid = 0;
      else if (idx)
        *value %= IDX_MOD;
    }
  d->offset += _size_for_type(d);
}

int	reg_valid(int reg)
{
  return (reg >= 1 && reg <= REG_NUMBER);
}

int	get_type(int descr, int pos)
{
  int	i;
  char	tmp[8];

  i = 0;
  while (i < 8)
    {
      tmp[8 - i - 1] = descr & 0x01;
      descr >>= 1;
      ++i;
    }
  i = 0;
  while (--pos)
    i += 2;
  i = (tmp[i] & 0x01) * 10 + (tmp[i + 1] & 0x01);
  return (i == 1 ? T_REG : i == 10 ? T_DIR : i == 11 ? T_IND : 0);
}

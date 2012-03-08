/*
** check_param.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
**
** Started on  Thu Jan 19 18:46:39 2012 lyoma guillou
** Last update mer. févr. 15 21:34:14 2012 gaby czegany
*/

#include <asm.h>

static int	_is_valid_reg(t_node *node)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (node->data[++i])
    {
      nb = (nb * 10) + (node->data[i] - '0');
      if (!my_is_number(node->data[i]) || nb <= 0 || nb > REG_NUMBER)
	{
	  my_puterr("Invalid register value.\n ");
	  return (FAILURE);
	}
    }
  if (node->label)
    return (FAILURE);
  return (node->data ? SUCCESS : FAILURE);
}

static int	_is_valid_dir(t_node *node)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  if (!node->data)
    return ((node->label && node->label[0] != '\0') ? SUCCESS : FAILURE);
  while (node->data[++i])
    {
      if (node->data && my_is_number(node->data[i]))
	nb = (nb * 10) + (node->data[i] - '0');
      if (i == 0 && node->data[i] != '-' && !my_is_number(node->data[i]))
	{
	  my_puterr("Invalid direct value.\n");
	  return (FAILURE);
	}
    }
  if (nb < 0 || nb > 512)
    {
      nb >>= 1;
      my_putstr("Warning: Direct value rescaled (Exceeded 0 or 512)\n");
    }
  return (SUCCESS);
}

static int	_is_valid_ind(t_node *node)
{
  int		i;

  i = -1;
  while (node->data ? node->data[++i] : node->label[++i])
    {
      if (node->data ? !my_is_number(node->data[i]) : !my_is_letter(node->label[i]))
	{
	  my_puterr("Invalid indirect value.\n");
	  return (FAILURE);
	}
    }
  if ((node->data != NULL) ^ (node->label != NULL))
    return (SUCCESS);
  return (FAILURE);
}

static const t_type	type_handler[MAX_FLAG] =
{
  { T_REG, _is_valid_reg },
  { T_IND, _is_valid_ind },
  { T_DIR, _is_valid_dir }
};

int		is_valid_type(t_node *act, t_node *node, int arg_pos)
{
  int		i;
  int		ret;
  int		type;

  i = 0;
  ret = 0;
  type = node->type;
  if (type & T_LAB)
    type ^= T_LAB;
  if (act->type & T_ACT)
    {
      while (my_strcmp(act->data, op_tab[i].mnemonique))
	++i;
      if (type & op_tab[i].type[arg_pos])
	{
	  i = -1;
	  while (++i < MAX_FLAG)
	    if (type & type_handler[i].flag)
	      ret = type_handler[i].fnc(node);
	}
    }
  return (ret);
}

/*
** check_param.c for check_param in /home/guillo_e//Documents/working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 19 18:46:39 2012 lyoma guillou
** Last update Mon Feb 20 18:08:06 2012 lyoma guillou
*/

#include <asm.h>

#define MAX_VAL	65025

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
	  return (0);
	}
    }
  if (node->label)
    return (0);
  return (node->data ? 1 : 0);
}

static int	_is_valid_dir(t_node *node)
{
  int		i;
  int		nb;
  int		len;

  i = (node->data && node->data[0] == '-') ? 0 : -1;
  nb = 0;
  while (!node->data && node->label[++i])
    if (!my_is_letter(node->label[i]) && node->label[i] != '\0')
      return (0);
  len = (node->data) ? my_strlen(node->data) : 0;
  while (node->data && node->data[++i])
    {
      if (node->data[0] != '-' && my_is_number(node->data[i]))
	nb = (nb * 10) + (node->data[i] - '0');
      if (nb > MAX_VAL)
	node->data[i] = '\0';
      if (!my_is_number(node->data[i]))
	{
	  my_puterr("Invalid direct value.\n");
	  return (0);
	}
    }
  if (node->data && (nb == 0 || i != len))
    my_puterr("Warning: Direct value rescaled (Exceeded 0 or 65025)\n");
  return (1);
}

static int	_is_valid_ind(t_node *node)
{
  int		i;
  int		nb;
  int		len;

  i = (node->data && node->data[0] == '-') ? 0 : -1;
  nb = 0;
  while (!node->data && node->label[++i])
    if (!my_is_letter(node->label[i]) && node->label[i] != '\0')
      return (0);
  len = (node->data) ? my_strlen(node->data) : 0;
  while (node->data && node->data[++i])
    {
      if (node->data[0] != '-' && my_is_number(node->data[i]))
	nb = (nb * 10) + (node->data[i] - '0');
      if (nb > MAX_VAL)
	node->data[i] = '\0';
      if (node->data ? !my_is_number(node->data[i]) : !my_is_letter(node->label[i]))
	{
	  my_puterr("Invalid indirect value.\n");
	  return (0);
	}
    }
  if (node->data && (nb == 0 || i != len))
    my_puterr("Warning: Direct value rescaled (Exceeded 0 or 65025)\n");
  return (1);
}

#define MAX_FLAG 3

typedef struct s_type
{
  int		flag;
  int		(*fnc)(t_node *);
} t_type;

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

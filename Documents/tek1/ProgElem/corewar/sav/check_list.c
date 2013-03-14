/*
** check_list.c for asm in /home/guillo_e//Documents/working/prog_elem/asm/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 18 15:35:30 2012 lyoma guillou
** Last update Wed Feb 15 12:53:46 2012 lyoma guillou
*/

#include <asm.h>

static int	_is_code(t_node *node, t_header *head)
{
  static int	code = 0;

  if ((node->type & T_DAT) && code == 1)
    return (1);
  if ((node->type & T_COD) && head->magic == 1)
    {
      code = 1;
      return (1);
    }
  my_puterr(".extend not found or .code not found\n");
  return (0);
}

static int	_is_action(t_node *node)
{
  int		i;

  i = 0;
  while ((op_tab + i) && op_tab[i].mnemonique)
    {
      if (!my_strcmp(node->data, op_tab[i].mnemonique))
	return (op_tab[i].nbr_args);
      ++i;
    }
  my_puterr("Instruction not found.\n");
  return (0);
}

static int	_is_valid_arg(t_node *node_act, t_node *tmp, int arg)
{
  int		prev;

  prev = tmp->prev->type;
  if (is_valid_type(node_act, tmp, arg) && (prev & (T_SEP | T_ACT) || !prev))
    return (1);
  my_puterr("Syntax error around '");
  my_puterr(node_act->data);
  my_puterr("' in argument '");
  my_puterr(tmp->data ? tmp->data : tmp->label);
  my_puterr("'.\n");
  return (0);
}

t_node		*is_valid_format(t_node *node)
{
  t_node	*tmp;
  int		nbr_args;
  int		max_arg;

  tmp = node;
  max_arg = _is_action(tmp);
  if ((nbr_args = max_arg) > 0 && max_arg < 4)
    {
      while (nbr_args > 0)
	{
	  tmp = tmp->next;
	  if (!(tmp->type & T_SEP))
	    {
	      if (!_is_valid_arg(node, tmp, max_arg - nbr_args))
		return (0);
	      --nbr_args;
	    }
	}
      return (tmp);
    }
  my_puterr("Instruction '");
  my_puterr(node->data);
  my_puterr("' may have been put in a wrong format.\n");
  return (0);
}

int		check_list(t_handler *hand)
{
  t_node	*tmp;
  int		line;

  tmp = hand->list->first;
  line = 1;
  while (tmp)
    {
      if (tmp->type & T_COD || tmp->type & T_DAT)
	{
	  if (!_is_code(tmp, hand->head))
	    return (0);
	}
      else if ((tmp = is_valid_format(tmp)) == NULL)
	{
	  my_puterr("Error was on instructiony line: ");
	  my_putnbr(line);
	  my_putchar('\n');
	  return (0);
	}
      ++line;
      tmp = tmp->next;
    }
  return (1);
}

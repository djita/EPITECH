/*
** check_list.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
**
** Started on  Wed Jan 18 15:35:30 2012 lyoma guillou
** Last update sam. mars 24 18:50:10 2012 gaby czegany
*/

# include       <asm.h>

static int	_is_code(t_node *node, t_header *head)
{
  static int	code = 0;

  if ((node->type & T_DAT) && my_strlen(node->data) <= 2 && code == 1)
    return (SUCCESS);
  if ((node->type & T_COD) && head->magic == 1)
    {
      code = 1;
      return (SUCCESS);
    }
  if (!head->magic)
    error(".extend not found or .code not found.");
  if (my_strlen(node->data) > 2)
    error(".code arguments lenght is invalid.");
  return (FAILURE);
}

static int	_is_action(t_node *node)
{
  int		i;

  i = 0;
  while ((op_tab + i) && op_tab[i].mnemonique)
    {
      if (node->data && !my_strcmp(node->data, op_tab[i].mnemonique))
	return (op_tab[i].nbr_args);
      ++i;
    }
  my_puterr("Error: Instruction '");
  my_puterr(node->data ? node->data : "(null)");
  my_puterr("' may have been put in a wrong format\n");
  return (FAILURE);
}

static int	_is_valid_arg(t_node *node_act, t_node *tmp, int arg)
{
  int		prev;

  prev = tmp->prev->type;
  if (is_valid_type(node_act, tmp, arg) && (prev & (T_SEP | T_ACT) || !prev))
    return (SUCCESS);
  my_puterr("Error: Syntax error around '");
  my_puterr(node_act->data);
  my_puterr("' in argument '");
  if (tmp->data || tmp->label)
    my_puterr(tmp->data ? tmp->data : tmp->label);
  else
    my_puterr("(null)");
  my_puterr("'");
  return (FAILURE);
}

t_node		*is_valid_format(t_node *node)
{
  t_node	*tmp;
  int		nb_arg;
  int		max_arg;
  int		nil;

  tmp = node;
  max_arg = _is_action(tmp);
  nb_arg = max_arg;
  while (nb_arg > 0 && nb_arg < 4)
    {
      tmp = tmp->next;
      if (!(tmp->type & T_SEP) && !_is_valid_arg(node, tmp, max_arg - nb_arg--))
	return (FAILURE);
      else if (tmp->label && get_label(tmp, &nil, tmp->label) == ERROR)
	{
	  label_error(tmp->label ? tmp->label : "(null)");
	  return (FAILURE);
	}
    }
  if (tmp->next && !(tmp->next->type & T_ACT))
    {
      my_puterr("Error: Invalid argument number");
      tmp = NULL;
    }
  return (tmp);
}

int		check_list(t_handler *hand)
{
  t_node	*tmp;
  int		line;

  tmp = hand->list->first;
  line = 0;
  if (!tmp)
    return (error("Empty file."));
  while (tmp)
    {
      if (tmp->type & T_COD || tmp->type & T_DAT)
	{
	  if (!_is_code(tmp, hand->head))
	    return (FAILURE);
	}
      else if ((tmp = is_valid_format(tmp)) == NULL)
	{
	  my_puterr(" => line: ");
	  my_putnbr(line);
	  my_puterr("\n");
	  return (FAILURE);
	}
      ++line;
      tmp = tmp->next;
    }
  return (SUCCESS);
}

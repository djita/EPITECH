/*
** misc.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 11:47:44 2012 louis duverdier
** Last update dim. mars 25 21:08:00 2012 gaby czegany
*/

# include       <asm.h>

int	get_param(int type)
{
  if (type)
  {
    type = type & T_LAB ? type ^ T_LAB : type;
    if (type & T_REG)
      return (V_REG);
    if (type & T_DIR)
      return (V_DIR);
    if (type & T_IND)
      return (V_IND);
  }
  return (0);
}

int	is_act(const char *d)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (!my_strcmp(op_tab[i].mnemonique, d))
	return (i);
      i += 1;
    }
  return (-1);
}

int	contains(const char *str, char c)
{
  while (*str && *str != c)
    ++str;
  return (*str == c);
}

static int      _is_index(t_node *node)
{
  int           action;

  while (node && node->type != T_ACT)
    node = node->prev;
  if (node)
  {
    action = is_act(node->data);
    if (action > 7 && action < 12)
      return (IND_SIZE);
  }
  return (DIR_SIZE);
}

int     get_length(t_node *node)
{
  int   type;
  int   action;

  type = node->type & T_LAB ? node->type ^ T_LAB : node->type;
  if (type & T_ACT)
  {
    action = is_act(node->data);
    if (op_tab[action].nbr_args > 1 || action == 15)
      return (2);
    else
      return (1);
  }
  else
  {
    if (type & T_REG)
      return (1);
    if (type & T_IND)
      return (IND_SIZE);
    if (type & T_DIR)
      return (_is_index(node));
  }
  return (0);
}

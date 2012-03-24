/*
** misc.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 11:47:44 2012 louis duverdier
** Last update sam. mars 24 19:19:32 2012 gaby czegany
*/

# include       <asm.h>

int     get_length(t_node *node)
{
  int   type;

  type = node->type & T_LAB ? node->type ^ T_LAB : node->type;
  if (type & T_ACT)
  {
    if (op_tab[is_act(node->data)].nbr_args > 1)
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
    if (type & T_DIR &&
        node->next && (node->next->type & T_DIR || node->prev->type & T_DIR))
      return (DIR_SIZE/2);
    if (type & T_DIR)
      return (DIR_SIZE);
  }
  return (0);
}

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

/*
** labels.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Mon Jan 23 15:02:04 2012 louis duverdier
** Last update Tue Jan 24 17:26:14 2012 louis duverdier
*/

#include <asm.h>

static void	_set_label(t_node *node)
{
  t_node	*tmp;

  if (node->next && node->next->type & T_ACT && node->next->next
      && !(node->next->next->type & T_ACT))
    {
      tmp = node->next->next;
      while (tmp)
        {
          if (!tmp->next || tmp->next->type & T_ACT || tmp->next->type & T_LAB
              || tmp->next->type & T_COD)
            {
              tmp->type |= T_LAB;
              tmp->label_ref = node->data;
              tmp = NULL;
            }
          else
            tmp = tmp->next;
        }
      return;
    }
  my_puterr("Warning: missformed file (label '");
  my_puterr(node->data);
  my_puterr("' incorrect). Skipped.\n");
}

void		set_labels(t_list *list)
{
  t_node	*node;
  t_node	*tmp;

  node = list->first;
  while (node)
    {
      if (node->type == T_LAB)
        {
          _set_label(node);
          tmp = node;
          node = node->next;
          list_remove(list, tmp);
        }
      else
        node = node->next;
    }
}

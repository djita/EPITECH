/*
** tree_funcs.c for mysh in /home/guillo_e//Documents/working/42sh/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 17:56:01 2012 lyoma guillou
** Last update Sat May 12 16:37:32 2012 lyoma guillou
*/

#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "lltree.h"

void		free_cmdl(t_cmd *tree)
{
  if (tree->prev)
    free_cmdl(tree->prev);
  if (tree->next)
    free_cmdl(tree->next);
  free(tree->name);
  free(tree);
}

t_cmd		*new_node()
{
  t_cmd		*new;

  new = malloc(sizeof(*new));
  if (!new)
    {
      fprintf(stderr, "New Node Allocation Error.\n");
      return (NULL);
    }
  new->name = NULL;
  new->flag = NIL;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

t_cmd		*append_next(t_cmd *node, t_cmd *elem)
{
  t_cmd		*tmp;

  if (node)
    {
      tmp = node;
      node->next = elem;
      return (node);
    }
  return (elem);
}

t_cmd		*append_prev(t_cmd *node, t_cmd *elem)
{
  t_cmd		*tmp;

  if (node)
    {
      tmp = node;
      node->prev = elem;
      return (node);
    }
  return (elem);
}

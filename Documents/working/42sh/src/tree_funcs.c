/*
** tree_funcs.c for mysh in /home/guillo_e//Documents/working/42sh/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 17:56:01 2012 lyoma guillou
** Last update Sun May 20 19:16:12 2012 lyoma guillou
*/

#include <stdlib.h>
#include <stdio.h>

#include "my.h"
#include "lltree.h"

void		free_cmdl(t_cmd *tree)
{
  if (tree)
    {
      if (tree->left)
	free_cmdl(tree->left);
      if (tree->right)
	free_cmdl(tree->right);
      if (tree->name)
	free(tree->name);
      free(tree);
    }
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
  new->left = NULL;
  new->right = NULL;
  return (new);
}

t_cmd		*append_right(t_cmd *node, t_cmd *elem)
{
  if (node)
    {
      node->right = elem;
      return (node);
    }
  return (elem);
}

t_cmd		*append_left(t_cmd *node, t_cmd *elem)
{
  if (node)
    {
      node->left = elem;
      return (node);
    }
  return (elem);
}

/*
** simple_btree.c for simple_btree in /home/guillo_e//Documents/working/tek2/piscine/D02a/ex01
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 19:12:43 2013 lyoma guillou
** Last update Thu Jan 10 21:21:01 2013 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>

#include "simple_btree.h"

t_bool		btree_is_empty(t_tree tree)
{
  return !tree;
}

unsigned int	btree_get_size(t_tree tree)
{
  int		x;

  x = 0;
  if (NULL != tree)
    {
      x = 1;
      if (tree->left)
	x += btree_get_size(tree->left);
      if (tree->right)
	x += btree_get_size(tree->right);
    }
  return x;
}

unsigned int	btree_get_depth(t_tree tree)
{
  int		l = 1;
  int		r = 1;

  if (tree)
    {
      if (tree->left)
	l += btree_get_depth(tree->left);
      if (tree->right)
	r += btree_get_depth(tree->right);
    }
  return (l >= r) ? l : r;
}

t_bool		btree_create_node(t_tree *node_ptr, double value)
{
  if (!*node_ptr)
    {
      *node_ptr = malloc(sizeof(*node_ptr));
      (*node_ptr)->value = value;
      return TRUE;
    }
  return FALSE;
}

t_bool		btree_delete(t_tree *root_ptr)
{
  if (!*root_ptr)
    return FALSE;
  *root_ptr = NULL;
  return TRUE;
}

double		btree_get_max_value(t_tree tree)
{
  double	l = 0;
  double	r = 0;
  double	val = 0;

  if (tree)
    {
      val = tree->value;
      if (tree->left)
	l = btree_get_max_value(tree->left);
      if (tree->right)
	r = btree_get_max_value(tree->right);
      l = (val >= l) ? val : l;
      r = (val >= r) ? val : r;
    }
  return (l >= r) ? l : r;
}

double		g_val = 0;
double		g_flag = 0;

double		btree_get_min_value(t_tree tree)
{
  if (!btree_is_empty(tree))
    {
      double	tmp;

      if (!btree_is_empty(tree->left))
	{
	  double	l;
	  l = btree_get_min_value(tree->left);
	  if (!l && !g_flag)
	    tmp = l;
	}
      if (!btree_is_empty(tree->right))
	{
	  double	r;
	  r = btree_get_min_value(tree->right);
	  if (!r && !g_flag)
	    tmp = (r < tmp) ? r : tmp;
	}
      if (!g_flag && !g_val)
	{
	  g_val = tmp;
	  g_flag = 1;
	}
      if (!tmp && !g_flag)
	g_val = (tmp < g_val) ? tmp : g_val;
      return (g_val);
    }
  return tree->value;
}

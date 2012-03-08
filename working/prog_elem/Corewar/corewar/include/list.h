/*
** list.h for mysh in /home/duverd_l/Documents/Projets/mysh
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Jan 31 12:49:51 2012 louis duverdier
** Last update Thu Feb 16 14:18:38 2012 louis duverdier
*/

#ifndef LIST_H_
#  define LIST_H_

#  include <my.h>

typedef struct s_node
{
  void		*data;
  struct s_node	*prev;
  struct s_node	*next;
} t_node;

typedef struct s_list
{
  t_node	*first;
  t_node	*last;
  int		size;
} t_list;

t_list	*list_create();
t_node	*node_create();
t_node	*node_create_from(void *);
t_node	*node_at(t_list *, int);
t_node	*list_pop(t_list *, t_node *);
void	list_append(t_list *, t_node *);
void	list_prepend(t_list *, t_node *);
void	list_insert(t_list *, t_node *, int pos);
void	list_free(t_list *, int);

#endif

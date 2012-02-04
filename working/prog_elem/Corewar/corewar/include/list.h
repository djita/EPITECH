/*
** list.h for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 16:23:57 2012 louis duverdier
** Last update Thu Jan 26 16:37:19 2012 louis duverdier
*/

#ifndef LIST_H_
#  define LIST_H_

#  include <corewar.h>
#  include <stdlib.h>

typedef header_t t_header;

typedef struct s_node
{
  t_header		*head;
  int			last_live;
  struct s_node	*prev;
  struct s_node	*next;
} t_node;

typedef struct s_list
{
  t_node		*first;
  t_node		*last;
  int			size;
} t_list;

t_list	*list_create();
t_node	*node_create();
void	list_remove(t_list *, t_node *);
void	list_append(t_list *, t_node *);
void	list_prepend(t_list *, t_node *);
void	list_free(t_list *);

#endif

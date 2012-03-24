/*
** list.h for include in /home/czegan_g/project/current/corewar/asm/include
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 14:44:00 2012 louis duverdier
** Last update ven. mars 23 00:37:57 2012 gaby czegany
*/

#ifndef LIST_H_
# define LIST_H_

# include       <stdlib.h>

typedef struct s_node
{
  int			type;
  char			*label;
  char			*label_ref;
  char			*data;
  struct s_node	        *prev;
  struct s_node	        *next;
} t_node;

typedef struct s_list
{
  t_node		*first;
  t_node		*last;
  int			size;
} t_list;

t_list	*list_create();
t_node	*node_create(int, char *, char *, char *);
void	list_remove(t_list *, t_node *);
void	list_append(t_list *, t_node *);
void	list_prepend(t_list *, t_node *);
void	list_free(t_list *);

#endif

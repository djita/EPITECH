/*
** list.h for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 17:39:22 2012 mickael falck
** Last update Fri May 11 17:44:57 2012 mickael falck
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

t_list		*add_link(t_list *prev, void *data);
t_list		*pop_link(t_list *link, void (*free_func)(void *));
void		flush_list(t_list *first, void (*free_func)(void *));

#endif /* !LIST_H_ */

/*
** chunk_list.h for malloc in /home/lastmikoi/Work/malloc
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 16:25:14 2013 mickael falck
** Last update jeu. janv. 31 17:09:16 2013 mickael falck
*/

#ifndef CHUNK_LIST_H_
# define CHUNK_LIST_H_
# include <sys/types.h>

typedef struct s_chunk_list
{
  size_t		size;
  void			*ptr;
  struct s_chunk_list	*prev;
  struct s_chunk_list	*next;
}		t_chunk_list;

t_chunk_list	*new_link(t_chunk_list *prev, size_t size, void *ptr);
void	*remove_link(t_chunk_list *toremove);

#endif /* !CHUNK_LIST_H_ */

/*
** my_malloc.h for malloc in /home/lastmikoi/Work/malloc
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 16:12:13 2013 mickael falck
** Last update jeu. janv. 31 16:58:29 2013 mickael falck
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_
# include <sys/types.h>
# include "chunk_list.h"

typedef struct s_g_mymalloc
{
  void		*chunk_start;
  t_chunk_list	*chunks;
  void		*chunk_end;
}		t_g_mymalloc;

void		*malloc(size_t size);
t_chunk_list	*is_allocated(void *ptr);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);

#endif /* !MY_MALLOC_H_ */

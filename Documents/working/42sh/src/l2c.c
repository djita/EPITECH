/*
** l2c.c for 42sh in /home/benjab_p//Dropbox/Documents/sys_u/42sh/42sh/src
** 
** Made by phedrik benjabria
** Login   <benjab_p@epitech.net>
** 
** Started on  Wed May  2 19:38:02 2012 phedrik benjabria
** Last update Fri May 11 12:29:19 2012 lyoma guillou
*/

#include <stdlib.h>

#include "42sh.h"

int		add_to_l2c(char	*data, t_token_list **list)
{
  t_token_list	*elem;

  elem = malloc(sizeof(t_token_list));
  if (elem == NULL)
    return (-1);
  elem->token = data;
  elem->next = *list;
  if (*list != NULL)
    (*list)->prev = elem;
  elem->prev = NULL;
  *list = elem;
  return (1);
}

int		free_l2c(t_token_list *list)
{
  t_token_list	*tmp;
  t_token_list	*tmp_free;

  tmp = list;
  while (tmp != NULL)
    {
      tmp_free = tmp->next;
      free(tmp);
      tmp = tmp_free;
    }
  return (0);
}

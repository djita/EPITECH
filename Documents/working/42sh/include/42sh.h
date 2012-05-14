/*
** 42sh.h for 42sh in /home/benjab_p//Dropbox/Documents/sys_u/42sh/42sh/src
** 
** Made by phedrik benjabria
** Login   <benjab_p@epitech.net>
** 
** Started on  Wed May  2 19:34:41 2012 phedrik benjabria
** Last update Fri May 11 12:03:18 2012 lyoma guillou
*/

#ifndef	_42SH_H_
# define _42SH_H_

# include <unistd.h>

typedef	struct		s_token_list
{
  char			*token;
  struct s_token_list	*next;
  struct s_token_list	*prev;
}			t_token_list;

int			add_to_l2c(char *data, t_token_list **list);
int			free_l2c(t_token_list *list);
t_token_list		*tokenise(char *str, size_t len);

#endif /* !_42SH_H */

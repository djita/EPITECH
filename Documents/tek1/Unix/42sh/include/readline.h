/*
** readline.h for include in /mnt/fedora_std/home/falck_m/Work/42sh/include
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:28:43 2012 mickael falck
** Last update Sun May 20 17:03:52 2012 mickael falck
*/

#ifndef READLINE_H_
# define READLINE_H_
# include <sys/types.h>
# include "list.h"
# include "history.h"
# define BLEN 65535
# define PROMPT "$>"

typedef struct	s_readline
{
  char		buff[BLEN + 1];
  char		*oldbuff;
  char		input[128];
  size_t	offset;
  t_list	*cur_cmd;
  t_history	*history;
}		t_readline;

char	*readline(void);

#endif /* !READLINE_H_ */

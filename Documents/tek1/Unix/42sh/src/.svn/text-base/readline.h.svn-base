/*
** readline.h for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:28:43 2012 mickael falck
** Last update Sat May 12 17:00:53 2012 mickael falck
*/

#ifndef READLINE_H_
# define READLINE_H_
# include <sys/types.h>
#include "list.h"

typedef enum
{
  CONTINUE,
  EXIT
}		t_e_exit;

int	capcmp(char *cap, const char *str);
int		parse_caps(char *buf, char *input, size_t *offset, t_list **cmd);
char		*readline(void);

#endif /* !READLINE_H_ */

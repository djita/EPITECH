/*
** history.h for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 17:38:18 2012 mickael falck
** Last update Sat May 12 15:15:32 2012 mickael falck
*/

#ifndef HISTORY_H_
# define HISTORY_H_
# include <sys/types.h>
# include "list.h"

typedef struct	s_history
{
  t_list	*cmds;
  char		*savepath;
}		t_history;

typedef struct	s_cmd
{
  char		*cmd;
  size_t	id;
}		t_cmd;

t_history		*get_history(void);
void	free_cmd(void *ptr);
void		free_history(void);
void		append_hist(char *cmd);
void		print_history(void);

#endif /* !HISTORY_H_ */

/*
** execute.h for include in /mnt/fedora_std/home/falck_m/Work/42sh/include
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 18 20:07:24 2012 mickael falck
** Last update Sun May 20 20:21:56 2012 mickael falck
*/

#ifndef EXECUTE_H_
# define EXECUTE_H_

# include "lltree.h"

typedef struct		s_exec
{
  enum	cmd_type	flag;
  int			(*fnc)(t_cmd *, int [2], int *);
}			t_exec;

int	exec_cmd(t_cmd *, int [2], int *);
int	exec_pipe(t_cmd *, int [2], int *);
int	exec_redir(t_cmd *, int [2], int *);
int	exec_logop(t_cmd *, int [2], int *);
int	exec_endl(t_cmd *, int [2], int *);
int	exec_node(t_cmd *, int [2], int *);
int	exec_tree(t_cmd *, int *);
int	execute(char *buff, int *stop);

#endif /* !EXECUTE_H_ */

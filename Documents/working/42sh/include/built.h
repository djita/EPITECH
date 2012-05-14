/*
** built.h for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:24:51 2012 lyoma guillou
** Last update Fri May 11 16:49:04 2012 lyoma guillou
*/

#ifndef _BUILT_H_
# define _BUILT_H_

typedef struct	s_built
{
  char		*cmd;
  int		(*fnc)(char **);
}		t_built;

#endif /* !_BUILT_H_ */

/*
** built.h for include in /mnt/fedora_std/home/falck_m/Work/42sh/include
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:24:51 2012 lyoma guillou
** Last update Sun May 20 21:39:35 2012 vincent bonmarchand
*/

#ifndef _BUILT_H_
# define _BUILT_H_
# define BLT_NOTFOUND -42

typedef struct	s_built
{
  char		*cmd;
  int		(*fnc)(char **, int fd[2]);
}		t_built;

int	my_echo(char **arg, int [2]);
int	my_cd(char **arg, int [2]);
int	my_env(char **arg, int [2]);
int	my_pwd(char **arg, int [2]);
int	built_in(char **arg, int fd[2]);

#endif /* !_BUILT_H_ */

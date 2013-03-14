/*
** echo.h for include in /mnt/fedora_std/home/falck_m/Work/42sh/include
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat May 12 16:30:36 2012 lyoma guillou
** Last update Sun May 20 20:23:33 2012 mickael falck
*/

#ifndef _ECHO_H_
# define _ECHO_H_

typedef enum
  {
    NO_NEWLINE = 1 << 0,
    DO_BACKSLASH = 1 << 1
  }	t_e_echo;

typedef	struct	s_symbol
{
  char		*pat;
  char		sym;
}		t_symbol;

int		my_echo(char **arg, int fd[2]);

#endif /* !_ECHO_H_ */

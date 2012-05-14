/*
** echo.h for e42sh in /home/guillo_e//Documents/working/test/unix
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat May 12 16:30:36 2012 lyoma guillou
** Last update Sat May 12 16:31:22 2012 lyoma guillou
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

#endif /* !_ECHO_H_ */

/*
** signal.c for mysh in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb 20 15:31:14 2012 lyoma guillou
** Last update Mon Feb 20 16:04:10 2012 lyoma guillou
*/

#include <my_sh.h>

typedef void (*sighandler_t)(int);

sighandler_t	signal(int signum, sighandler_t handler);

void		handle_signal(int signo)
{
  if (signo)
    my_putchar('\n');
}

/*
** serv.h for minitalk server in /home/guillo_e//Documents/working/unix/minitalk/server
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:39:40 2012 lyoma guillou
** Last update Thu Mar 15 17:38:37 2012 lyoma guillou
*/

#ifndef	SERV_H_
# define SERV_H_

int		xwrite(int, char *, int);
void		*xmalloc(int);

void		my_putchar(char);
void		my_putstr(char *);
void		my_puterr(char *);
void		my_putnbr(unsigned int);

#endif

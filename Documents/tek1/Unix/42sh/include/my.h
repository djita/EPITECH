/*
** my.h for mysh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Apr 26 15:43:59 2012 lyoma guillou
** Last update Sun May 20 13:49:43 2012 lyoma guillou
*/

#ifndef _MY_H_
# define _MY_H_

# include <stdlib.h>

int		is_scrpt(char c);
int		is_pipe(char c);
int		is_sep(char c);
int		is_end_line(char c);
int		is_oper(char c);

int		my_putchar(char c);
int		my_putstr(char *str);
int		my_puterr(char *err);
void		my_putnbr(int nb);

#endif /* !_MY_H_ */

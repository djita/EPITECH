/*
** infin_mult.h for infin_mult.h in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 10:33:01 2011 exam_user
** Last update Thu Nov 24 10:34:47 2011 exam_user
*/

#ifndef INFIN_MULT_H_
#define INFIN_MULT_H_

void		my_putchar(char c);
void		my_putstr(char *str);
int		is_num(char c);
int		my_numlen(unsigned char *str);
char		*my_revstr(unsigned char *str);
char		*my_memset(unsigned char *str);
char		*mult_to_res(unsigned char *x, unsigned char *y, unsigned char *res);
char		*carry_add(unsigned char *str);
void		infin_mult(char *av1, char *av2);

#endif

/*
** get_next_line.h for get_next_line in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Nov 18 14:35:21 2011 lyoma guillou
** Last update Thu Nov 24 19:23:38 2011 lyoma guillou
*/

#ifndef		GET_NEXT_LINE_H_
#define		GET_NEXT_LINE_H_

#define		BUFF_SIZE		800
#define		READ_SIZE		80

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);
char		*my_strcpy(char *dst, char *src);
char		*get_next_line(const int fd);

#endif

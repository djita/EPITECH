/*
** get_next_line.h for get_next_line in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Nov 18 14:35:21 2011 lyoma guillou
** Last update Wed Jan 11 10:13:36 2012 lyoma guillou
*/

#ifndef		GET_NEXT_LINE_H_
#define		GET_NEXT_LINE_H_

#define		BUFF_SIZE		5242881
#define		READ_SIZE		5242880

int		my_strlen(char *str);

char            *my_memset(char *str, int size);

char		*my_strcpy(char *dst, char *src);

char		*get_next_line(const int fd);

#endif

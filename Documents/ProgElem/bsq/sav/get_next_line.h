/*
** get_next_line.h for get_next_line in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Nov 18 14:35:21 2011 lyoma guillou
** Last update Tue Dec  6 17:37:02 2011 lyoma guillou
*/

#ifndef		GET_NEXT_LINE_H_
#define		GET_NEXT_LINE_H_

#define		BUFF_SIZE		4096
#define		READ_SIZE		4095

char		*my_strset(char *str, int size);
int		my_bufflen(char *str);
char		*my_buffreset(char *dst, char *src);
char		*get_next_line(const int fd);

#endif

/*
** my.h for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 20:05:18 2012 lyoma guillou
** Last update Tue Apr 24 22:45:25 2012 lyoma guillou
*/

#ifndef MY_H_
# define MY_H_

# define BUFFLEN	1024
# define TABLEN		200

int		my_strlen(char *str);

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterr(char *err);
void		my_putnbr(int nb);

char		*epur_str(char *str);
char		*cut_str(char *str);

char		*my_strdup(char *src);
char		*my_strndup(char *src, int len);

char		*my_strcpy(char *dst, char *src);
char		*my_strncpy(char *dst, char *src, int len);

int		my_strcmp(char *src, char *dst);
int		my_strncmp(char *src, char *dst, int len);

void		*my_memset(void *ptr, int c, int len);

char		*get_next_line(int fd);

#endif

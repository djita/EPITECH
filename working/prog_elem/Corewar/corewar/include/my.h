/*
** my.h for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 16:05:22 2012 louis duverdier
** Last update Thu Jan 26 17:12:08 2012 louis duverdier
*/

#ifndef MY_H_
#  define MY_H_

#  include <stdlib.h>
#  include <fcntl.h>
#  include <unistd.h>
#  include <sys/types.h>

#  define MY_UNUSED(data) (void)data

int		my_is_space(char);
int		my_is_number(char);
int		my_is_letter(char);
int		my_getnbr(const char *);
void	my_putchar(char);
void	my_putnbr(int);
void	my_puterr(const char *);
void	my_putstr(const char *);
int		my_strcmp(const char *, const char *);
int		my_strlen(const char *);
char	*my_strcpy(char *, const char *);
char	*my_strncpy(char *, const char *, int);
char	*my_strcat(char *, const char *);
char	*my_strdup(const char *);
char	*my_strndup(const char *, int);
void	*my_memset(void *, int, size_t);
int		xopen(const char *, int);
void	xclose(int);
void	xwrite(int, const char *, int);
void	*xmalloc(size_t);

#endif

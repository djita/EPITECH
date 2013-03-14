/*
** my.h for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 16:13:41 2012 louis duverdier
** Last update Wed Mar 21 18:04:19 2012 louis duverdier
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdarg.h>

# define MY_UNUSED(data) (void)data

int	my_is_space(char);
int	my_is_number(char);
int	my_is_letter(char);
int	my_getnbr(const char *);
int	my_getnbr_hex(const char *);
void	my_putchar(char);
void	my_putnbr(int);
void	my_puterr(const char *);
void	my_putstr(const char *);
void	my_err(int, ...);
void	*my_memset(void *, int, size_t);
int	my_strcmp(const char *, const char *);
int	my_strlen(const char *);
char	*my_strcpy(char *, const char *);
char	*my_strncpy(char *, const char *, int);
char	*my_strcat(char *, const char *);
char	*my_strdup(const char *);
char	*my_strndup(const char *, int);
int	xopen(const char *, int);
void	xclose(int);
void	xwrite(int, const char *, int);
void	*xmalloc(size_t);

#endif

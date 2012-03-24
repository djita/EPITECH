/*
** my.h for include in /home/czegan_g/project/current/corewar/asm/include
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 16:13:41 2012 louis duverdier
** Last update ven. mars 23 00:38:48 2012 gaby czegany
*/

#ifndef MY_H_
# define MY_H_

# include       <stdlib.h>
# include       <fcntl.h>
# include       <unistd.h>
# include       <sys/types.h>

# define MY_UNUSED(data)        (void)data

int             my_getnbr(char *str);
int             my_getnbr_hexa(const char *);

int		my_is_space(char);
int		my_is_number(char);
int		my_is_letter(char);
int		my_is_alphanum(char);

void	        my_putchar(char);
void	        my_putchar_fd(int, char);
void	        my_putnbr(int);
void	        my_puterr(const char *);
void	        my_putstr(const char *);

int		my_strlen(const char *);
char	        *my_strcpy(char *, const char *);
char	        *my_strncpy(char *, const char *, int);
int		my_strcmp(const char *, const char *);
char	        *my_strcat(char *, const char *);
char	        *my_strdup(const char *);
char	        *my_strndup(const char *, int);

int	        xopen(const char *, int);
int	        xopen_create(const char *, int, int);
void	        xclose(int);
void	        xwrite(int, const char *, int);
void	        *xmalloc(size_t);

void            *my_memset(void *, int, int);
void            *my_memcpy(void *, void *, int);

#endif

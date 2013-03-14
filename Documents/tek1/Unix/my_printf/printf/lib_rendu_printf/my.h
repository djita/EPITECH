/*
** my.h for my.h in /home/guillo_e//afs/rendu/piscine/Jour_09/ex_02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 13 10:33:31 2011 lyoma guillou
** Last update Fri Nov 25 17:16:54 2011 lyoma guillou
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

int     is_alpha(char c);
int	is_num(char c);
int	is_low_alpha(char c);
int	is_up_alpha(char c);
int     is_over_int(int nb, char sp);
int	is_minialpha(char c);
int	is_bigalpha(char c);

int	my_isneg(int n);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int     my_str_isalpha(char *str);

int	my_getnbr(char *str);

int	my_swap(int *a, int *b);

int	my_strlen(char *str);
int     my_numlen(unsigned int nb, int base_len);

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putcstr(char *str);
int	my_put_nbr(int nb);
int	my_putnbr(int nb);
int	my_putunnbr(unsigned nb);
int	my_put_oct(char *num);
int	my_put_hexa(char *num);
int	my_putoctal(char c, char *base_to);
int	my_putnbr_base(unsigned int nb, char *base_to, int opt);
int	my_nbr_base(unsigned int x, char opt);
int	my_power_rec(int nb, int power);

char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char    *my_strstr(char *str, char *to_find);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strlowcase(char *str);
char	*my_strupcase(char *str);
char	*my_strcapitalize(char *str);
int	my_strlcat(char *dest, char *src, int size);
int     my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
void	my_sort_int_tab(int *tab, int size);

int	modulo_check(va_list ap, char opt);
int	my_printf(const char *format, ...);






#endif

/*
** my.h for my.h in /home/guillo_e//afs/rendu/piscine/Jour_09/ex_02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 13 10:33:31 2011 lyoma guillou
** Last update Sat Oct 29 23:57:49 2011 lyoma guillou
*/

#ifndef		MY_H_
#define		MY_H_

#define		BUFF_SIZE 2147483648

void	my_putchar(char c);
int	my_isneg(int nb);
void	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);

#endif

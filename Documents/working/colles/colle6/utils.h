/*
** utils.h for carre in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 20:05:49 2012 lyoma guillou
** Last update Mon May 21 21:08:30 2012 lyoma guillou
*/

#ifndef UTILS_H_
# define UTILS_H_

int	my_strlen(char *str);
void	my_putstr(char *str);
void	*xmalloc(int size);
int	my_strcmp(char *str1, char *str2);
char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str);

int	my_getnbr(char *str);
int	my_getnbr_base(char *str, char *base);

#endif /* !UTILS_H_ */

/*
** lib.h for lib.h in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:46:16 2012 marc deletang
** Last update Mon May  7 22:41:27 2012 lyoma guillou
*/

#ifndef	LIB_H_
# define LIB_H_

void		*xmalloc(int);
int		xwrite(int, char *, int);
int		my_strlen(char *);
void		my_putstr(char *);
char		*my_strcpy(char *, char *);
int		my_strcmp(char *, char *);
char		*my_strdup(char *);
char		*my_strncmp(char *, char *, int);
int		my_tablen(const char **tab);

#endif /* !LIB_H_ */

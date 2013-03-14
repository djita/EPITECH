/*
** txtcnt.h for txtcnt in /u/all/guillo_e/public/deleta_m
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 19:29:12 2012 marc deletang
** Last update Tue May 29 22:50:31 2012 lyoma guillou
*/

#ifndef TXTCNT_H_
# define TXTCNT_H_

# define MAX_ASCII 128

typedef enum
  {
    NIL = 1 << 0,
    SORT = 1 << 1,
    ORD = 1 << 2,
    REV = 1 << 3,
    FULL = 1 << 4,
    OTF = 1 << 5
  }	t_e_opt;

typedef struct	s_opts
{
  t_e_opt	flag;
  int		start;
}		t_opts;

int		g_char_tab[MAX_ASCII];

int		my_strlen(char *);
int		my_tablen(char **tab);

void		my_putchar(char );
void		my_putstr(char *);
void		my_putnbr(int );

void		*xmalloc(int );

char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
int		my_strcmp(char *str1, char *str2);
int		my_strncmp(char *str1, char *str2, int n);
void		my_bzero(void *, int);

void		show_ord_count(int len);
void		reverse_show_ord_count(int len);

void		count_and_sort(int len, t_e_opt flag);
void		reverse_count_and_sort(int len, t_e_opt flag);

void		text_count(int, char **, t_e_opt);
t_opts		get_opt(int, char **);

#endif /* !TXTCNT_H_ */

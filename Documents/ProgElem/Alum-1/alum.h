/*
** alum.h for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 08:56:00 2012 lyoma guillou
** Last update Sat Feb 11 15:12:33 2012 lyoma guillou
*/

#ifndef	ALUM_H_
#define	ALUM_H_

#define	SYM		'!'
#define READ_SIZE	4096

#include <stdlib.h>
#include <unistd.h>

int		my_putchar(int);
int		my_putstr(char *);
int		my_putnbr(int);

int		my_strlen(char *);
int		my_tablen(char **);
int		my_intlen(int);

int		char_alpha(char);
int		my_getnbr(char *);

void		*xmalloc(int);

void		*my_memset(void *, int, int);

void		alum_show(char **, int);
int		alum_check(char **);
char		**alum_tab(int);
char		**alum_entry(char *, char **);

char		**my_str_to_wordtab(char *);

int		clear_scrn(void);

#endif

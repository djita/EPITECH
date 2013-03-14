/*
** my.h for my.h in /home/guillo_e//afs/rendu/piscine/Jour_09/ex_02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 13 10:33:31 2011 lyoma guillou
** Last update Sun Oct 30 06:01:06 2011 lyoma guillou
*/

#ifndef		MY_H_
#define		MY_H_

#define		BUFFER_LEN 4095

typedef enum	e_colle
{
  COLLE1_1 = 1 << 0,
  COLLE1_2 = 1 << 1,
  COLLE1_3 = 1 << 2,
  COLLE1_4 = 1 << 3,
  COLLE1_5 = 1 << 4
}		t_colle;

typedef struct	s_sqr
{
  int		lin;
  int		col;
  int		lin_nb;
  int		col_nb;
  char		*buffer;
  t_colle	colle;
}		t_sqr;

typedef struct	s_desc
{
  char		top_left;
  char		top_right;
  char		bot_left;
  char		bot_right;
  char		lin;
  char		col;
}		t_desc;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void            print_size(t_sqr *sqr);
void            print_colle(t_sqr *sqr);
t_sqr           *s_sqr_new(char *buffer);
t_desc          *s_desc_new(void);
t_desc          *colle1_1();
t_desc          *colle1_2();
t_desc          *colle1_3();
t_desc          *colle1_4();
t_desc          *colle1_5();
t_colle         init_colle(char *buffer);
void            colle(t_sqr *sqr, t_desc *desc, int i, t_colle colle);
void            call_colle(t_sqr *sqr, int i);
int             lin_number(char *buffer);
int             col_number(char *buffer);
void            what_is_this_glue(char *buffer);

#endif

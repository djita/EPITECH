/*
** push_swap.h for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 16:45:32 2012 lyoma guillou
** Last update Sun Jan  8 20:02:26 2012 lyoma guillou
*/

#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

typedef struct	s_list
{
  int		val;
  char		name;
  struct s_list	*next;
  struct s_list *prev;
}		t_list;

typedef struct	s_swap
{
  t_list	*l_a;
  t_list	*l_b;
}		t_swap;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putnbr(int nb);

void		show_list(t_list *list);

int		is_numeric(char c);
int		my_getnbr(char *str);
int		*my_get_int_tab(int ac, char **av);

t_list		*swap_list(t_list *list);
void		swap_double(t_list *list_a, t_list *list_b);
t_list		*relink_first(t_list *src, t_list *dst);
t_swap		*push_to_a(t_swap *swap);
t_swap		*push_to_b(t_swap *swap);

t_list		*rotate_list(t_list *list);
void		rotate_double(t_list *list_a, t_list *list_b);
t_list		*rev_rotate_list(t_list *list);
void		rev_rotate_double(t_list *list_a, t_list *list_b);

t_list		*init_elem(int value, char list_name);
t_list		*add_to_list(t_list *list, t_list *elem);
t_list		*circle_list(int *val, int len, char name);

void		swap_sort(t_swap *swap);

#endif

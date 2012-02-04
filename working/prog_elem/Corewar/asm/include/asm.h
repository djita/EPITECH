/*
** asm.h for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 14:46:20 2012 louis duverdier
** Last update Thu Jan 26 17:54:49 2012 lyoma guillou
*/

#ifndef ASM_H_
#  define ASM_H_

#  include <my.h>
#  include <list.h>
#  include <op.h>

#  define ALL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789+-"
#  define LETTER_CHARS "abcdefghijklmnopqrstuvwxyz"
#  define NUM_CHARS "0123456789"
#  define MAX_LINE_LEN 4096
#  define T_ACT 16
#  define T_SEP 32
#  define T_COD 64
#  define T_DAT 128

typedef header_t t_header;

typedef struct s_handler
{
  t_list	*list;
  t_header	*head;
} t_handler;

int		is_act(const char *);
int		contains(const char *, char);

void	parse(t_handler *, const char *);
void	set_labels(t_list *);
void	handle_define(t_handler *, const char *, int *);

int		is_valid_type(t_node *act, t_node *node, int arg_pos);
t_node		*is_valid_format(t_node *node);
int		check_list(t_handler *hand);

#endif

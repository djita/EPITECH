/*
** asm.h for include in /home/czegan_g/project/current/corewar/asm/include
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 14:46:20 2012 louis duverdier
** Last update mar. févr. 21 14:13:10 2012 gaby czegany
*/

#ifndef ASM_H_
#  define ASM_H_

#  include <my.h>
#  include <list.h>
#  include <op.h>

#  define FAILURE       0
#  define SUCCESS       1

#  define ALL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789+-"
#  define LETTER_CHARS "abcdefghijklmnopqrstuvwxyz"
#  define NUM_CHARS "0123456789"
#  define MAX_LINE_LEN 4096
#  define T_ACT 16
#  define T_SEP 32
#  define T_COD 64
#  define T_DAT 128
#  define ACTION_LENGTH 8

#  define V_REG 1
#  define V_DIR 2
#  define V_IND 3

#  define TOTAL_TYPE	1

#  define PARAM_LEN	8
#  define MAXPRM_VAL	255

typedef header_t t_header;

typedef struct s_handler
{
  t_list	*list;
  t_header	*head;
  unsigned char *last_area;
  unsigned char *cursor;
} t_handler;

#  define MAX_FLAG      3

typedef struct s_type
{
  int		flag;
  int		(*fnc)(t_node *);
} t_type;

int	get_param(int type);
int		is_act(const char *);
int		contains(const char *, char);

void	parse(t_handler *, const char *);
void	set_labels(t_list *);
void	handle_define(t_handler *, const char *, int *);

int		is_valid_type(t_node *act, t_node *node, int arg_pos);
t_node		*is_valid_format(t_node *node);
int		check_list(t_handler *hand);

unsigned char   *build(t_handler *);
unsigned char   *build_param(unsigned char *, t_node *, t_handler *, int);

int		add_size(int lenght, unsigned char *ptr);

#endif

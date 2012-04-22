/*
** asm.h for include in /home/czegan_g/work/school/corewar/asm/include
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 14:46:20 2012 louis duverdier
** Last update dim. mars 25 21:28:26 2012 gaby czegany
*/

#ifndef ASM_H_
# define ASM_H_

# include       <my.h>
# include       <list.h>
# include       <op.h>

# define ERROR          -1
# define FAILURE        0
# define SUCCESS        1

# define ALLOC          1
# define FREED          2
# define STOP           4

# define ALL_CHARS      "abcdefghijklmnopqrstuvwxyz_0123456789+-"
# define LETTER_CHARS   "abcdefghijklmnopqrstuvwxyz"
# define NUM_CHARS      "0123456789"

# define MAX_LINE_LEN   4096
# define ACTION_LENGTH  8

# define T_ACT          16
# define T_SEP          32
# define T_COD          64
# define T_DAT          128

# define V_REG          1
# define V_DIR          2
# define V_IND          3

# define MAX_VAL	65025
# define MAX_FLAG       3
# define MAX_PARAM      3

# define LABEL_AFTER    1
# define LABEL_BEFORE   2

# define ADD_AREA       1
# define SUB_AREA       2

# define COUNTER_LEN	8

# define ABS(x)         ((x) < 0 ? -(x) : x)

typedef header_t        t_header;
typedef struct  s_handler
{
  t_list	*list;
  t_header	*head;
  t_node        *last_act;
  unsigned char *counter;
  unsigned char *last_area;
} t_handler;

typedef struct  s_type
{
  int		flag;
  int		(*fnc)(t_node *);
} t_type;

typedef struct  s_param
{
  int		flag;
  unsigned char *(*fnc)(t_handler *, unsigned char *, t_node *);
} t_param;

typedef unsigned char   uchar;

int	is_act(const char *);
int	contains(const char *, char);

void	parse(t_handler *, const char *);
void	set_labels(t_list *);
void	handle_define(t_handler *, const char *, int *);

int	is_valid_type(t_node *act, t_node *node, int arg_pos);
t_node	*is_valid_format(t_node *node);
int	check_list(t_handler *hand);

int     get_length(t_node *);
int	get_param(int);

uchar   *build(t_handler *);
uchar   *build_body(uchar *, t_node *, t_handler *);
uchar   *build_param(t_handler *, t_node *, uchar *);
int             get_label(t_node *, int *, char *);

int	write_in_area(int, uchar *, int, char);

int     error(char *text);
void    usage(char *);
void    warning(char *);
void    msg(char *, char *);
void	label_error(char *);

#endif

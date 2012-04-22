/*
** corewar.h for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Feb 21 14:14:07 2012 louis duverdier
** Last update Sat Mar 24 16:55:57 2012 louis duverdier
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "my.h"
# include "list.h"
# include "op.h"

# define MAGIC_LEN 4
# define NAME_PADDING 8
# define COMMENT_PADDING 4
# define MAX_ACTIONS 16

# if (REG_SIZE == 1)
typedef char t_reg;
# elif (REG_SIZE == 2)
typedef short int t_reg;
# else
typedef int t_reg;
# endif

struct		s_act;

typedef struct	s_handler
{
  struct s_act	*act_ptr;
  char		*mem;
  t_list	*champ_list;
  int		cycle_to_dump;
  int		cycle_to_die;
  int		current_cycle;
  int		alive_nbr;
  int		done;
}		t_handler;

typedef struct	s_champ
{
  char		*name;
  char		*comment;
  char		*mem;
  char		alive;
  int		champ_id;
  int		mem_pos;
  int		mem_len;
  int		last_live;
  t_list	*process_list;
}		t_champ;

typedef struct	s_process
{
  t_reg		reg[REG_NUMBER + 1];
  unsigned int	pc;
  char		carry;
  int		next_action;
  int		exec_cycle;
  void		(*act)(struct s_handler *, struct s_process *);
  t_champ	*champ;
}		t_process;

typedef struct	s_act
{
  char		code;
  void		(*fnc)(t_handler *, t_process *);
}		t_act;

typedef struct	s_data
{
  t_handler	*h;
  t_process	*p;
  int		type;
  int		descr;
  int		offset;
  int		valid;
  int		index;
  int		size;
}		t_data;

t_champ		*create_champ(int, int);
t_process	*create_process(t_champ *);
int		check_id(t_handler *, int, int);
int		check_magic(t_handler *, int, const char *);
void		init_mem(t_handler *);
void		init_ptr(t_handler *);
void		extract_data(int, t_champ *);
void		get_value(t_data *, int *, int, int);
int		get_type(int, int);
int		data_int(t_handler *, unsigned int, int);
void		main_loop(t_handler *);
void		dump_memory(t_handler *);
void		insert(t_handler *, const char *, unsigned int, int);
int		parse_file(t_handler *, const char *, int *, int *);
int		reg_valid(int);
char		*number_to_str(unsigned int);
void		act_live(t_handler *, t_process *);
void		act_add(t_handler *, t_process *);
void		act_sub(t_handler *, t_process *);
void		act_and(t_handler *, t_process *);
void		act_or(t_handler *, t_process *);
void		act_xor(t_handler *, t_process *);
void		act_jmp(t_handler *, t_process *);
void		act_fork(t_handler *, t_process *);
void		act_lfork(t_handler *, t_process *);
void		act_aff(t_handler *, t_process *);
void		act_st(t_handler *, t_process *);
void		act_sti(t_handler *, t_process *);
void		act_ld(t_handler *, t_process *);
void		act_ldi(t_handler *, t_process *);
void		act_lld(t_handler *, t_process *);
void		act_lldi(t_handler *, t_process *);

#endif

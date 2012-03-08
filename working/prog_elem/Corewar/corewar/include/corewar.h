/*
** corewar.h for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Feb 21 14:14:07 2012 louis duverdier
** Last update Tue Feb 21 16:41:31 2012 louis duverdier
*/

#ifndef COREWAR_H_
#  define COREWAR_H_

#  include <my.h>
#  include <list.h>
#  include <op.h>

#  if (REG_SIZE == 1)
typedef char t_reg;
#  elif (REG_SIZE == 2)
typedef short int t_reg;
#  else
typedef int t_reg;
#  endif

typedef struct s_champ
{
  char		*name;
  char		*comment;
  char		alive;
  int		champ_id;
  int		last_live;
  int		dump_nbr;
  t_list	*process_list;
} t_champ;

typedef struct s_process
{
  t_reg		reg[REG_NUMBER + 1];
  t_reg		pc;
  char		carry;
  int		next_action;
  t_champ	*champ;
} t_process;

typedef struct s_handler
{
  char		*mem;
  t_list	*champ_list;
  int		cycle_to_die;
} t_handler;

#endif

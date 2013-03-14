/*
** lltree.h for mysh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 17:35:24 2012 lyoma guillou
** Last update Fri May 11 14:00:43 2012 lyoma guillou
*/

#ifndef _LLTREE_H_
# define _LLTREE_H_

/* /!\ FIXME /!\ */

/*
** CMDS = commandes
** PIPE = pipes
** OLOG = operators
** SLNT = silent
** RDRC = redirect
** ENDL = end of line
** QUOT = quote
** VSET = variable set
** VCON = variable content
** NIL = null
*/

enum		cmd_type
  {
    CMDS,
    PIPE,
    OLOG,
    SLNT,
    RDRC,
    ENDL,
    QUOT,
    VSET,
    VCON,
    NIL
  };

typedef struct	s_cmd
{
  char		*name;
  enum cmd_type	flag;
  struct s_cmd	*prev;
  struct s_cmd	*next;
}		t_cmd;

typedef struct	s_scrpt
{
  const char	type;
  t_cmd		*(*fnc)(char *, int);
}		t_scrpt;

typedef struct	s_operat
{
  const char	*type;
  t_cmd		*(*fnc)(char *, int, int);
}		t_operat;

void		free_cmdl(t_cmd *tree);
t_cmd		*new_node();
t_cmd		*append_next(t_cmd *node, t_cmd *elem);
t_cmd		*append_prev(t_cmd *node, t_cmd *elem);

t_cmd		*set_var(char *str, int pos);
t_cmd		*val_var(char *str, int pos);
t_cmd		*str_var(char *str, int pos);
t_cmd		*str_pur(char *str, int pos);

t_cmd		*op_pipe(char *str, int pos, int len);
t_cmd		*op_or(char *str, int pos, int len);
t_cmd		*op_slnt(char *str, int pos, int len);
t_cmd		*op_and(char *str, int pos, int len);
t_cmd		*op_rdrc(char *str, int pos, int len);
t_cmd		*op_endl(char *str, int pos, int len);

t_cmd		*rec_scrpt(char *src, int pos);
t_cmd		*rec_operat(char *src, int pos);
t_cmd		*line_parser(char *str, int len);

#endif /* !_LLTREE_H_ */

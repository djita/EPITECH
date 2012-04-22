/*
** parse.h for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 30 17:21:09 2012 lyoma guillou
** Last update Tue Apr 10 17:21:11 2012 lyoma guillou
*/

#ifndef PARSE_H_
# define PARSE_H_

# define BUFF_SIZE	4096

typedef struct	s_room
{
  char		*name;
  unsigned int	x_pos;
  unsigned int	y_pos;
  struct s_room	*next;
}		t_room;

typedef struct	s_pipe
{
  char		*entry;
  char		*exit;
  struct s_pipe	*next;
}		t_pipe;

typedef struct	s_list
{
  t_room	*r_first;
  t_room	*r_last;
  t_pipe	*p_first;
  t_pipe	*p_last;
}		t_list;

int		xwrite(int, char *, int);
int		xread(int, char *, int);
void		*xmalloc(int);

void		my_putchar(char);
void		my_putstr(char *);
void		my_putnbr(int);

int		is_sep(char);
int		is_num(char);
int		is_low(char);
int		is_up(char);
int		is_alphanum(char);

int		my_tablen(char **);

t_list		init_list(void);
t_list		append_pipe(t_list, t_pipe *);
t_list		append_room(t_list, t_room *);
t_pipe		*get_pipe(char **);
t_room		*get_room(char **);

char		*get_next_line(int fd);
char            *get_next_word(char *str);
int             count_word(char *str);
char            **my_str_to_wordtab(char *str);

#endif

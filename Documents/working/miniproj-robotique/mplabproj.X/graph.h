#ifndef GRAPH_H_
# define GRAPH_H_

# define GLENGTH	200
# define MAX_TRIES	10
# define DEG		1
# define FAR		2

# define ABS(x)		(((x) < 0) ? (-x) : (x))

typedef	struct		s_graph
{
  unsigned char		iread;
  unsigned char		iwrite;
  unsigned char		buff[GLENGTH];
  unsigned char		is_full:1;
}		        t_graph;

char	my_put_nbr(char nb);
void	initgraph(void);
char	send_graph(t_graph *graph);
void	add_point_to_graph(char val, t_graph *graph);
char	switch_val_type(char val, char kind);

extern t_graph deg_graph;
extern t_graph pot_graph;

#endif

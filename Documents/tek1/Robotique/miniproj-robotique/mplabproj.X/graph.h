#ifndef GRAPH_H_
# define GRAPH_H_

# define GLENGTH	200

# define ABS(x)		(((x) < 0) ? (-x) : (x))

typedef	struct		s_graph
{
  unsigned char		iread;
  unsigned char		iwrite;
  char			buff[GLENGTH];
  unsigned char		is_full:1;
}		        t_graph;

char	my_put_nbr(int nb);
void	initgraph(void);
char    send_graph(t_graph *graph);
void	add_point_to_graph(char val, t_graph *graph);

extern t_graph deg_graph;
extern t_graph pot_graph;

#endif

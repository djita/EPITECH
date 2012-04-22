#include "graph.h"
#include "serial.h"

#pragma udata udata1
t_graph deg_graph;
#pragma udata udata2
t_graph pot_graph;
#pragma udata

void	initgraph()
{
  deg_graph.buff[0] = 0;
  deg_graph.iread = 0;
  deg_graph.iwrite = 0;
  pot_graph.buff[0] = 0;
  pot_graph.iread = 0;
  pot_graph.iwrite = 0;
}

void	add_point_to_graph(char val, t_graph *graph)
{
  graph->buff[graph->iwrite++] = val;
  if (graph->iwrite >= GLENGTH)
    {
      if (!graph->is_full)
        graph->is_full = 1;
      else if (graph->iread >= GLENGTH)
        graph->iread = 0;
      else
        ++graph->iread;
      graph->iwrite = 0;
    }
}

char		switch_val_type(char val, char kind)
{
  unsigned char	x = -1;
  static char	toggle = -1;

  if (kind == 0)
    {
      toggle = -toggle;
      if (toggle == 1)
	while (++x != GLENGTH)
	  deg_graph.buff[x] = (9/5) * deg_graph.buff[x] + 32;
      else
	while (++x != GLENGTH)
	  deg_graph.buff[x] = (5/9) * deg_graph.buff[x] - 32;
      return (0);
    }
  else
    return ((kind == DEG) ? ((9/5) * val + 32) : ((5/9) * val - 32));
}

static char    force_send(char c)
{
  char        tries;

  tries = 0;
  while (!putchar(c) && (tries++ < MAX_TRIES));
  if (tries >= MAX_TRIES)
    return (-1);
  return (0);
}

static char         force_putstr(const rom char *c)
{
  unsigned char   i;

  i = 0;
  while (c[i])
    if (!force_send(c[i++]))
      return (0);
  return (1);
}

unsigned int     get_bornes(t_graph *graph, char *max, char *min)
{
  unsigned char i;
  unsigned char pos;
  unsigned char grph_len;

  i = 0;
  *max = graph->buff[graph->iread];
  *min = *max;
  grph_len = (graph->is_full) ? (GLENGTH) : (graph->iwrite);
  while (i < grph_len)
    {
      pos = ((graph->iread) + i % GLENGTH);
      if (graph->buff[pos] > *max)
        *max = graph->buff[pos];
      else if (graph->buff[pos] < *min)
        *min = graph->buff[pos];
    }
  return (ABS(*max - *min));
}

char    print_all_the_points_in_interval(t_graph *graph, char val)
{
  int i;
  unsigned char grph_len;
  unsigned char pos;
  unsigned char skipped;

  i = 0;
  skipped = 0;
  grph_len = (graph->is_full) ? (GLENGTH) : (graph->iwrite);
  while (i < grph_len)
    {
      pos = ((graph->iread) + i % GLENGTH);
      if ((graph->buff[pos] >= (val - 2))
          || (graph->buff[pos] >= (val + 2)))
        {
          while (skipped < i)
            if (!force_putstr(" "))
              return (0);
          if (!force_putstr("."))
            return (0);
        }
      ++i;
    }
}

void    fix_interval(unsigned int *diff, char *max, char *min)
{
  if ((ABS(*max) % 5) > 2)
    {
      *max += 5;
      ++(*diff);
    }
  if ((ABS(*min) % 5) > 2)
    {
      *min -= 5;
      ++(*diff);
    }
}

char    draw_footer(t_graph *graph)
{
  unsigned char i;
  unsigned char grph_len;
  char          ret;

  if (!force_putstr("   |"))
    return (0);
  i = 0;
  grph_len = (graph->is_full) ? (GLENGTH) : (graph->iwrite);
  while (i < grph_len)
    {
      if (!force_putstr("_____"))
        return (0);
      i += 5;
    }
  if (!force_putstr("__>\n"))
    return (0);
  if (!force_putstr("    "))
    return (0);
  i = 0;
  while (i < grph_len)
    {
      if (!(ret = my_put_nbr(i)) < 0)
        return (0);
      while (ret++ < 5)
        if (!force_putstr(" "))
          return (0);
      i += 5;
    }
    if (!force_putstr("    mesure\n"))
        return (0);
}

char    send_graph(t_graph *graph)
{
  unsigned int i;
  char max;
  char min;
  unsigned int diff;
  char ret;

  i = 0;
  diff = get_bornes(graph, &max, &min);
  fix_interval(&diff, &max, &min);
  if (!force_putstr("T°\n   ^\n"))
    return (0);
  while (i < diff)
    {
      if ((ret = my_put_nbr(max)) < 0)
        return (0);
      while (ret < 3)
        if (!force_putstr(" "))
          return (0);
      if (!print_all_the_points_in_interval(graph, max))
        return (0);
      if (!force_putstr("\n"))
        return (0);
      i += 5;
    }
  if (!draw_footer(graph))
    return (0);
  return (1);
}


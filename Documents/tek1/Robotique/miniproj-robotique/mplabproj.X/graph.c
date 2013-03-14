#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

#pragma udata udata1
t_graph deg_graph;
#pragma udata udata2
t_graph pot_graph;
#pragma udata

static void         putstr(const rom char *c)
{
  unsigned char   i;

  i = 0;
  while (c[i])
    putchar(c[i++]);
}

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
  if ((graph->iwrite >= GLENGTH) || graph->is_full)
    {
      graph->is_full = 1;
      if ((graph->iread + 1) >= GLENGTH)
        graph->iread = 0;
      else
        ++graph->iread;
      graph->iwrite %= GLENGTH;
    }
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
      ++i;
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
      pos = (((graph->iread) + i) % GLENGTH);
      if ((graph->buff[pos] >= (val - 2))
          && (graph->buff[pos] <= (val + 2)))
        {
          while (skipped++ < i)
            putstr(" ");
          putstr(".");
        }
      ++i;
    }
  return (1);
}

void    fix_interval(unsigned int *diff, char *max, char *min)
{
  char	tmp;

  tmp = ABS(*max);
  if ((tmp % 10) < 5)
    tmp = tmp - (tmp % 10);
  else if ((tmp % 10) > 5)
    tmp = tmp - (tmp % 10) + 10;
  *max = ((*max < 0) ? (-tmp - 5) : (tmp + 5));
  tmp = ABS(*min);
  if ((tmp % 10) < 5)
    tmp = tmp - (tmp % 10);
  else if ((tmp % 10) > 5)
    tmp = tmp - (tmp % 10) + 10;
  *min = ((*min < 0) ? (-tmp - 5) : (tmp - 5));
  *diff = ABS(*max - *min);

}

char    draw_footer(t_graph *graph)
{
  unsigned char i;
  unsigned char grph_len;
  char          ret;

  putstr("   |");
  i = 0;
  grph_len = (graph->is_full) ? (GLENGTH) : (graph->iwrite);
  while (i < grph_len)
    {
      putstr("_____");
      i += 5;
    }
  putstr("__>\n");
  putstr("    ");
  i = 0;
  while (i < grph_len)
    {
      ret = my_put_nbr(i);
      while (ret++ < 5)
        putstr(" ");
      i += 5;
    }
  putstr("    mesure\n");
  return (1);
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
  putstr("T* ^\n   |\n");
  while (i < diff)
    {
      ret = my_put_nbr(max - i);
      while (ret++ < 3)
	putchar(' ');
      putchar('|');
      print_all_the_points_in_interval(graph, max - i);
      putstr("\n");
      i += 5;
    }
  draw_footer(graph);
  return (1);
}


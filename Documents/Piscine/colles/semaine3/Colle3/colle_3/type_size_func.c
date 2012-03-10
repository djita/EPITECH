/*
** type_size_func.c for colle 3 in /home/guillo_e//working/colle/colle3
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 19:58:24 2011 lyoma guillou
** Last update Sat Oct 29 23:38:28 2011 lyoma guillou
*/

int	is_type(char type)
{
  if (type == 'o')
    return (1);
  if (type == '/' || type == '*')
    return (2);
  if (type == 'A' || type == 'B')
    return (3);
  return (0);
}

int	col_count(char *buffer)
{
  int	col;

  col = 0;
  while (buffer[col] != '\n')
    col = col + 1;
  return (col);
}

int	lin_count(char *buffer)
{
  int	ind;
  int	lin;

  ind = 0;
  lin = 1;
  while (buffer[ind])
    {
      if (buffer[ind] == '\n')
	lin = lin + 1;
      ind = ind + 1;
    }
  return (lin);
}

int	is_colle_type(char *buffer, int col, int lin)
{
  char	first;
  char	angle;
  char	last;

  first = buffer[0];
  angle = buffer[col];
  last = buffer[col + ((col + 2) * lin - 1)];
  if (first == 'A' && angle == 'A' && last == 'C')
    return (3);
  if (first == 'A' && angle == 'C' && last == 'C')
    return (4);
  if (first == 'A' && angle == 'C' && last == 'A')
    return (5);
  return (0);
}

int	what_is_this_glue(char *buffer)
{
  int	col;
  int	lin;
  int	pat;

  col = col_count(buffer);
  lin = lin_count(buffer);
  pat = is_type(buffer[0]);
  if (3 == pat)
    {
      if (col != 1 && lin != 1)
	pat = is_colle_type(buffer, col, lin);
    }
  colle_print(pat, col, lin);
  return (0);
}

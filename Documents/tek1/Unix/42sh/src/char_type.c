/*
** char_type.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 13:46:15 2012 lyoma guillou
** Last update Sun May 20 13:51:52 2012 lyoma guillou
*/

int		is_scrpt(char c)
{
  return ((c == '='));
}

int		is_pipe(char c)
{
  return ((c == '&' || c == '|' || c == '<' || c == '>' || c == ';'));
}

int		is_sep(char c)
{
  return ((c <= ' '));
}

int		is_end_line(char c)
{
  return ((c == '\n' || c == '\0'));
}

int		is_oper(char c)
{
  return ((is_scrpt(c) || is_pipe(c)));
}

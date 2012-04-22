/*
** str_format.c for lem-in in /home/guillo_e//Documents/working/lem-in/lem-in
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 19:47:17 2012 lyoma guillou
** Last update Tue Apr 10 17:49:10 2012 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>
#include <parse.h>

char		*get_next_line(int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*dup;

  if (buffer == 0)
    {
      buffer = xmalloc(BUFF_SIZE * sizeof(*buffer));
      bzero(buffer, BUFF_SIZE);
    }
  xread(fd, buffer + len, BUFF_SIZE - len);
  len = 0;
  while (buffer[len] && buffer[len] != '\n')
    ++len;
  dup = xmalloc(len + 1 * sizeof(*dup));
  bzero(dup, len + 1);
  my_strncpy(dup, buffer, len);
  my_strcpy(buffer, buffer + len + 1);
  if (dup[0] == '\0')
    free(buffer);
  return ((dup[0] != '\0') ? dup : NULL);
}

char            *get_next_word(char *str)
{
  char          *ret;
  int           i;

  i = 0;
  while (str[i] && is_alphanum(str[i]))
    ++i;
  ret = malloc(i + 1 * sizeof(*ret));
  bzero(ret, i);
  my_strncpy(ret, str, i);
  my_strcpy(str, (str[i] == '\0') ? str + i : str + i + 1);
  if (ret[0] == '\0')
    {
      free(ret);
      return (NULL);
    }
  return (ret);
}

int             count_word(char *str)
{
  int           i;
  int           cnt;

  i = 0;
  cnt = 0;
  while (str[i])
    {
      if (is_alphanum(str[i]) && (i == 0 || is_sep(str[i - 1])))
        ++cnt;
      ++i;
    }
  return (cnt);
}

char            **my_str_to_wordtab(char *str)
{
  char          **tab;
  char          *word;
  int           i;
  int		len;

  len = count_word(str);
  tab = xmalloc((len + 1) * sizeof(*tab));
  i = 0;
  while ((word = get_next_word(str)))
    {
      tab[i] = word;
      ++i;
    }
  tab[len] = NULL;
  return (tab[0] != '\0' ? tab : NULL);
}

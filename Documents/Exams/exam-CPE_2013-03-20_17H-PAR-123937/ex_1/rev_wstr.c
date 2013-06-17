#define _BSD_SOURCE

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int is_sep(char c)
{
  return ((c == ' ' || c == '\t'));
}

int is_char(char c)
{
  return ((c > ' '));
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

size_t getw_index(char *str)
{
  size_t i = 0;
  while (is_sep(str[i]))
    ++i;
  return i;
}

size_t getw_length(char *str)
{
  size_t i = 0;
  while (is_char(str[i]))
    ++i;
  return i;
}

void rev_wstr(char *str)
{
  int i = 0;
  if (!str || !str[0])
    return;
  if (is_sep(str[0]))
    {
      rev_wstr(str + getw_index(str));
      if (strlen(str) != getw_index(str))
	my_putchar(' ');
    }
  else
    {
      rev_wstr(str + getw_length(str));
      for (i = 0; is_char(str[i]); ++i)
	my_putchar(str[i]);
    }
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      char *buff = strdup(av[1]);
      rev_wstr(buff);
    }
  my_putchar('\n');
  return (0);
}

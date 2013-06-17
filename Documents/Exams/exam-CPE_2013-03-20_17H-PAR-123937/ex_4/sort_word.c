#define _BSD_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_sep(char c)
{
  return ((c <= ' '));
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  write(1, str, i);
}

char upc(char c)
{
  if (c >= 'a' && c <= 'z')
    return (c - ('a' - 'A'));
  return c;
}

char *to_up(char *str)
{
  int i = 0;
  for (i = 0; str[i]; ++i)
    str[i] = upc(str[i]);
  return str;
}

int word_count(char *str)
{
  int cnt = 0;
  size_t i = 0;
  int word = 0;
  for (i = 0; i <= strlen(str); ++i)
    {
      if (!is_sep(str[i]))
	word = 1;
      if (is_sep(str[i]) && 1 == word)
	{
	  word = 0;
	  ++cnt;
	}
    }
  return cnt;
}

void sort_word(char *str)
{
  char **tab = malloc((word_count(str) + 1) * sizeof(*tab));
  char *buff;
  int i = 0;
  int swap = 1;

  buff = strtok(str, " ");
  tab[i] = strdup(buff);
  while (buff != NULL)
    {
      ++i;
      buff = strtok(NULL, " ");
      if (buff != NULL)
	tab[i] = strdup(buff);
    }
  tab[i] = NULL;
  while (swap)
    {
      swap = 0;
      i = 0;
      while (tab[i] && tab[i + 1])
	{
	  if (strcmp(to_up(strdup(tab[i])), to_up(strdup(tab[i + 1]))) > 0)
	    {
	      buff = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = buff;
	      swap = 1;
	      i = 0;
	    }
	  ++i;
	}
    }

  for (i = 0; tab[i]; ++i)
    {
      my_putstr(tab[i]);
      if (NULL != tab[i + 1])
	my_putchar(' ');
    }
}

int main(int ac, char **av)
{
  char *buff;
  if (ac > 1)
    {
      buff = strdup(av[1]);
      sort_word(buff);
    }
  my_putchar('\n');
  return 0;
}

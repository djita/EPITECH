#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *get_shortest(char **tab)
{
  int i = 0;
  int j = 0;
  size_t len = strlen(tab[0]);

  for (i = 0; tab[i]; ++i)
    if (strlen(tab[i]) < len)
      {
	j = i;
	len = strlen(tab[i]);
      }
  return (strdup(tab[j]));
}

int fits_in_str(char *str, char *dst)
{
  int i = 0;
  size_t len = strlen(str);
  for (i = 0; dst[i]; ++i)
    if (!strncmp(str, dst + i, len))
      return 1;
  return 0;
}

int fits_in_all(char *str, int len, char **tab)
{
  int i = 0;
  int flag = 0;
  
  for (i = 0; i < len; ++i)
    flag += fits_in_str(str, tab[i]);
  return ((flag == len) ? 1 : 0);
}

char *next_pattern(char *str)
{
  static char *pattern = NULL;
  static int size = 0;
  static int index = 0;
  int len = strlen(str);
  int s_len = 0;

  if (pattern == NULL)
    pattern = strdup(str);
  s_len = strlen(pattern);
  if (len <= (s_len + index))
    {
      index = 0;
      size = s_len - 1;
    }
  if (size == 0)
    return NULL;
  pattern = strndup(str + index, size);
  ++index;
  return pattern;
}

void str_maxlenoc(int len, char **tab)
{
  char *src = get_shortest(tab);
  char *str = strdup(src);

  while (str && 0 == fits_in_all(str, len, tab))
    str = next_pattern(src);
  printf("%s", (!str) ? "" : str);
}

int main(int ac, char *av[])
{
  if (ac > 1)
    str_maxlenoc(ac - 1, av + 1);
  printf("\n");
  return 0;
}

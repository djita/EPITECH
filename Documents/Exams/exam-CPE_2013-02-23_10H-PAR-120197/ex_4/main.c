static int _is_alpha(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int my_strlen(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

char *my_strncpy(char *dest, const char *src, int n)
{
  int i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = '\0';
  return dest;
}

char *next_word_with_size(char *str, int size)
{
  char *word = NULL;
  int i = 0;
  while (!_is_alpha(str[i]))
    ++i;
  strncpy(str, str + i, i);
  i = 0;
  while (_is_alpha(str[i]) && i < size)
    ++i;
  if (!_is_alpha(str[i]))
    {
      word = malloc(i * sizeof(*word));
      my_strncpy(word, str, i);
    }
  return word;
}

void ord_alphlong(char *str)
{
  
}

int main(int ac, char **av)
{
  if (ac > 1)
    ord_alphlong(av[1]);
  my_putchar('\n');
  return 0;
}

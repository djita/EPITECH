static int tab[128];

int my_strlen(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

void my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

void _is_in_str(char c, char *str)
{
  int i = 0;
  while (i < my_strlen(str))
    {
      if (c == str[i])
	tab[c] = 1;
      ++i;
    }
}

void common_str(char *str, char *dst)
{
  int x = 0;
  int i = 0;
  while (i < my_strlen(str))
    _is_in_str(str[i++], dst);
  i = 0;
  while (i < 128)
    {
      x += tab[i];
      ++i;
    }
  my_putnbr(x);
}

int main(int ac, char **av)
{
  if (ac == 3)
    common_str(av[1], av[2]);
  my_putchar('\n');
  return 0;
}

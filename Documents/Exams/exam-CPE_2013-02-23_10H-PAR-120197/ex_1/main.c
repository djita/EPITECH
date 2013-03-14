int my_strlen(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

void half_str(char *str)
{
  int i = 0;
  while (i < my_strlen(str))
    {
      my_putchar(str[i]);
      i += 2;
    }
}

int main(int ac, char **av)
{
  int i = 0;
  if (ac > 1)
    while (i < ac - 1)
      {
	half_str(av[i + 1]);
	my_putchar('\n');
	++i;
      }
  else
    my_putchar('\n');
  return 0;
}

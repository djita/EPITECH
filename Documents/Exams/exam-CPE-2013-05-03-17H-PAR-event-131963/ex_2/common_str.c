void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putnbr(unsigned int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int is_checked(char c)
{
  static char tab[256];
  int val = c;

  if (!tab[val])
    {
      tab[val] = 1;
      return 0;
    }
  return 1;
}

void common_str(char *src, char *dst)
{
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int val = 0;

  for (i = 0; src[i]; ++i)
    {
      for (j = 0; dst[j]; ++j)
	{
	  if (src[i] == dst[j] && !is_checked(src[i]))
	    ++val;
	}
    }
  my_putnbr(val);
}

int main(int ac, char **av)
{
  if (ac == 3)
    common_str(av[1], av[2]);
  write(1, "\n", 1);
}

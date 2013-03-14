int is_shown(char c)
{
  static char tab[128];
  int i = c;

  if (!tab[i])
    {
      tab[i] = 1;
      return 0;
    }
  return 1;
}

void inter(char const *str, char const *dst)
{
  int i = 0;
  int j = 0;
  for (i = 0; dst[i]; ++i)
    {
      if (dst[i] == str[j] || (!dst[i + 1] && str[j]))
	{
	  if (dst[i] == str[j] && !is_shown(str[j]))
	    write(1, &str[j], 1);
	  ++j;
	  i = 0;
	}
    }
}

int main(int ac, char **av)
{
  if (ac >= 3)
    inter(av[1], av[2]);
  write(1, "\n", 1);
}

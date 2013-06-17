void half_str(char *str)
{
  int i = 0;
  int len = 0;
  while (str[len])
    ++len;
  while (i < len)
    {
      write(1, &str[i], 1);
      i += 2;
    }
}

int main(int ac, char **av)
{
  int i = 1;
  if (ac >= 2)
    {
      while (i < ac)
	{
	  half_str(av[i]);
	  write(1, "\n", 1);
	  ++i;
	}
    }
  else
    write(1, "\n", 1);
}

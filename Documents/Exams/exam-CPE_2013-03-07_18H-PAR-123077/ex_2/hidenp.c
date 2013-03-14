int hidenp(char const * src, char const * dst)
{
  int i = 0;
  int j = 0;

  for (i = 0; dst[i] && src[j]; ++i)
    if (src[j] == dst[i])
      ++j;
  return (((!j && !i) || !src[j]) ? 1 : 0);
}

int main(int ac, char **av)
{
  char c = 0;
  if (ac >= 3)
    {
      c = hidenp(av[1], av[2]);
      c += '0';
      write(1, &c, 1);
    }
  write(1, "\n", 1);
}

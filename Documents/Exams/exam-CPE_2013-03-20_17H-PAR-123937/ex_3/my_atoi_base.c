int baselen(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

int my_pow(int nb, int pow)
{
  if (pow > 0)
    return (nb * my_pow(nb, pow - 1));
  return 1;
}

int get_int(char c, char *base)
{
  int i = 0;
  while (base[i] && c != base[i])
    ++i;
  return i;
}

int my_atoi_base(char *str, char *base)
{
  int x = 0;
  if (str[0] == '-')
    {
      x = my_atoi_base(str + 1, base);
      return -x;
    }
  if (!str || !str[0])
    return 0;
  x = my_atoi_base(str + 1, base);
  x += get_int(str[0], base) * my_pow(baselen(base), (baselen(str) - 1));
  return x;
}

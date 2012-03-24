/*
** get_next_line.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 14:21:48 2012 louis duverdier
** Last update ven. mars 23 00:33:53 2012 gaby czegany
*/

# include       <get_next_line.h>

static void	_pop_data(char *buffer, int i)
{
  int	offset;
  char	*tmp;

  tmp = buffer + i + 1;
  offset = 0;
  while (tmp[offset])
    {
      buffer[offset] = tmp[offset];
      offset += 1;
    }
  buffer[offset] = 0;
}

static char	*_get_data(char **buffer, int *offset)
{
  int		i;
  char		*tmp;

  i = 0;
  while ((*buffer)[i])
    {
      if ((*buffer)[i] == '\n')
        {
          (*buffer)[i] = 0;
          tmp = my_strdup(*buffer);
          _pop_data(*buffer, i);
          *offset = my_strlen(*buffer);
          return (tmp);
        }
      i += 1;
    }
  *offset = my_strlen(*buffer);
  if (*offset > 0)
    {
      *offset = 0;
      tmp = my_strdup(*buffer);
      return (tmp);
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static int	offset = 0;
  static char	*buffer = NULL;
  int		len;

  if (!buffer)
    {
      buffer = xmalloc(BUFFER_MAX_SIZE * sizeof(char));
      buffer[0] = 0;
    }
  if ((len = read(fd, buffer + offset, MAX_CHAR_READ - offset)) == -1 ||
      (offset == 0 && len == 0))
    {
      free(buffer);
      buffer = NULL;
      return (NULL);
    }
  buffer[len + offset] = 0;
  return (_get_data(&buffer, &offset));
}

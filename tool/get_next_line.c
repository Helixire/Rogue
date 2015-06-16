/*
** get_next_line.c for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 16:19:49 2015 Blank Pierre
** Last update Sat May 16 16:19:49 2015 Blank Pierre
*/

#include <stdlib.h>
#include <unistd.h>
#include "tool.h"

static char	*add_char(char *str, const char c)
{
  char		*ret;
  int		i;

  if (str == NULL)
    {
      if ((ret = malloc(sizeof(*ret) * 2)) == NULL)
	return (NULL);
      ret[0] = c;
      ret[1] = 0;
    }
  else
    {
      if ((ret = malloc(sizeof(*ret) * (my_strlen(str) + 2))) == NULL)
	{
	  free(str);
	  return (NULL);
	}
      i = -1;
      while (str[++i])
	ret[i] = str[i];
      ret[i] = c;
      ret[i + 1] = 0;
      free(str);
    }
  return (ret);
}

static void	scrol(char *str, const int size)
{
  int		i;

  i = -1;
  while (++i < size && str[i] != 0)
    str[i] = str[i + 1];
  str[i] = 0;
}

char		*get_next_line(const int fd)
{
  static char	buf[SIZE];
  char		*ret;

  ret = NULL;
  while (buf[0] != '\n')
    {
      if (buf[0] == 0)
	{
	  if (read(fd, buf, SIZE) <= 0 || buf[0] == 0)
	    return (ret);
	}
      else
	{
	  if ((ret = add_char(ret, buf[0])) == NULL)
	    return (NULL);
	  scrol(buf, SIZE);
	}
    }
  scrol(buf, SIZE);
  return ((ret == NULL) ? add_char(ret, 0) : ret);
}

/*
** parser.c for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 17:13:32 2015 Blank Pierre
** Last update Sat May 16 17:13:32 2015 Blank Pierre
*/

#include <stdlib.h>
#include "tool.h"

static int	parse_count(char *str, char *delim)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && index_of(delim, str[i]) != -1)
	++i;
      if (str[i] != 0)
	{
	  ++j;
	  while (str[i] && index_of(delim, str[i]) == -1)
	    ++i;
	}
    }
  return (j);
}

static int	parse_init(char *str, char *delim, char ***result)
{
  if (str == NULL || str[0] == 0)
    {
      *result = NULL;
      return (1);
    }
  if ((*result = malloc(sizeof(**result) * (parse_count(str, delim) + 1)))
      == NULL)
    return (1);
  (*result)[0] = NULL;
  return (0);
}

char	**parse(char *str, char *delim)
{
  int	i;
  int	j;
  int	k;
  char	**result;

  if (parse_init(str, delim, &result) == 1)
    return (result);
  i = 0;
  k = -1;
  while (str[i])
    {
      while (str[i] && index_of(delim, str[i]) != -1)
	++i;
      j = i;
      if (str[i] != 0)
	{
	  while (str[i] && index_of(delim, str[i]) == -1)
	    ++i;
	  result[++k] = my_strndup(str + j, i - j);
	}
    }
  result[++k] = NULL;
  return (result);
}

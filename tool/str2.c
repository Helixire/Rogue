/*
** str2.c for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 16:13:11 2015 Blank Pierre
** Last update Sat May 16 16:13:11 2015 Blank Pierre
*/

# include <stdlib.h>
# include "tool.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = -1;
  while (str[++i] && str[i] <= '9' && str[i] >= '0')
    {
      nb *= 10;
      nb += str[i] - '0';
    }
  return (nb);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] && str1[i] == str2[i])
    i += 1;
  return (str1[i] - str2[i]);
}

int	index_of(const char *str, const char c)
{
  int	i;

  if (str != NULL)
    {
      i = -1;
      while (str[++i])
	if (str[i] == c)
	  return (i);
    }
  return (-1);
}

char	*my_strndup(char *str, int n)
{
  char	*result;
  int	i;

  if ((result = malloc(n + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && i < n)
    result[i] = str[i];
  result[i] = 0;
  return (result);
}

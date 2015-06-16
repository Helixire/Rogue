/*
** str3.c for emble in /home/helixire/rendu/BocalEmblem/II : Path of Radiance
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sun May 17 17:34:01 2015 Blank Pierre
** Last update Sun May 17 17:34:01 2015 Blank Pierre
*/

#include <stdlib.h>
#include <unistd.h>
#include "tool.h"

int	free_grid(int **grid)
{
  int	y;

  if (grid != NULL)
    {
      y = -1;
      while (grid[++y] != NULL)
	free(grid[y]);
      free(grid);
    }
  return (1);
}

int	free_tab(char **tab)
{
  int	i;

  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
	free(tab[i]);
      free(tab);
    }
  return (1);
}

void	my_putname(char *str)
{
  int	i;
  int	c;

  i = my_strlen(str) - 1;
  while(i >= 0 && str[i] != '/')
    i -= 1;
  while ((c = str[++i]))
    {
      if (c <= 'z' && c >= 'a')
	c -= 32;
      (void)write(1, &c, 1);
    }
  my_putstr(NORM);
  (void)write(1, "\n", 1);
}

void	my_revstr(char *str)
{
  int	i;
  int	len;
  char	c;

  i = -1;
  len = my_strlen(str) - 1;
  while (++i < len / 2)
    {
      c = str[i];
      str[i] = str[len - i];
      str[len - i] = c;
    }
}

void	int_to_str(int nb, char str[])
{
  int	i;
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      neg = 1;
      nb *= -1;
    }
  i = -1;
  while (nb > 9)
    {
      str[++i] = nb % 10 + '0';
      nb /= 10;
    }
  str[++i] = nb % 10 + '0';
  if (neg)
    str[++i] = '-';
  str[i + 1] = 0;
  my_revstr(str);
}

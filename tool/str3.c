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

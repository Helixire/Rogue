/*
** init.c for emblem in /home/helixire/rendu/BocalEmblem/II : Path of Radiance
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sun May 17 17:03:18 2015 Blank Pierre
** Last update Sun May 17 17:03:18 2015 Blank Pierre
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "game.h"

static int	add_to_grid(int ***grid, int *lint)
{
  int		i;
  int		**tmp;

  if (*grid == NULL)
    {
      if (((*grid) = malloc(sizeof(**grid) * 2)) == NULL)
	return (my_error(EM));
      (*grid)[0] = lint;
      (*grid)[1] = NULL;
    }
  else
    {
      i = 0;
      while ((*grid)[i] != NULL)
	i += 1;
      if ((tmp = malloc(sizeof(*tmp) * (i + 2))) == NULL)
	return (my_error(EM));
      tmp[i + 1] = NULL;
      tmp[i] = lint;
      while (--i >= 0)
	tmp[i] = (*grid)[i];
      free(*grid);
      *grid = tmp;
    }
  return (0);
}

static int	add_line(char *line, int ***grid, int *sizeX)
{
  char		**tab;
  int		i;
  int		*lint;

  tab = parse(line, " \t");
  free(line);
  if (tab == NULL)
    return (my_error(EM));
  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if (*sizeX == 0)
    *sizeX = i;
  if (*sizeX != i || (lint = malloc(sizeof(*lint) * i)) == NULL)
    return (my_error(EM) + free_tab(tab) - 1);
  i = -1;
  while (tab[++i] != NULL)
    lint[i] = my_getnbr(tab[i]);
  free_tab(tab);
  if (add_to_grid(grid, lint) == 1 || lint[0] != 0 || lint[*sizeX - 1] != 0)
    return (my_error(WF));
  return (0);
}

static int	init_end(int **grid, t_unit **unit,
			 int sizeX, int sizeY, int fd)
{
  int		i;
  char		*str;
  char		**tab;
  int		tmp[4];

  i = -1;
  while (++i < sizeX)
    if (grid[0][i] != 0 || grid[sizeY - 1][i] != 0)
      return (my_error(WF));
  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] != 0)
	{
	  tab = parse(str, " \t");
	  free(str);
	  if (tab == NULL)
	    return (my_error(EM));
	  i = -1;
	  while (tab[++i] != NULL && i < 4)
	    tmp[i] = my_getnbr(tab[i]);
	  free_tab(tab);
	  while (i < 4)
	    tmp[i++] = 0;
	  if (add_unit(unit, tmp) == 1)
	    return (my_error(EM));
	}
    }
  close(fd);
  return (0);
}

int	init(char *file, int ***grid, t_unit **unit)
{
  int	fd;
  int	x;
  int	y;
  char	*tmp;

  if (!((fd = my_strlen(file)) > 4 && (fd = open(file, O_RDONLY)) != -1))
    return (my_error(EO));
  x = 0;
  y = 0;
  *grid = NULL;
  while ((tmp = get_next_line(fd)) != NULL && tmp[0] != 0)
    {
      if (add_line(tmp, grid, &x) == 1)
	return (my_error(GE));
      y += 1;
    }
  if (x < 3 || y < 3)
    return (my_error(GS) - 1);
  return (init_end(*grid, unit, x, y, fd));
}

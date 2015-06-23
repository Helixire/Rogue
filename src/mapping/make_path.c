/*
** make_path.c for Rogue in /home/chau_b/projet_ext/Rogue/map
** 
** Made by alexandre chau
** Login   <chau_b@epitech.net>
** 
** Started on  Tue Jun 23 16:52:31 2015 alexandre chau
** Last update Tue Jun 23 19:23:14 2015 alexandre chau
*/

#include "game.h"
/*
int	path()
{
  int	**map;
  int	i;

  i = 0;
  if (!(map = malloc(((TAILLE_MIN * 2) + 1) * sizeof(*map))))
    return (-1);
  while (i < ((TAILLE_MIN * 2) + 1))
    {
      if (!(map[i] = malloc(((TAILLE_MIN * 2) + 1) * sizeof(**map))))
	return (-1);
      i++;
    }
  map[i] = NULL;
}
*/

int	gene_aleatoire(int type, int ***map)
{
  t_unit	*osef;

  return (init("map/start", map, &osef));
}

int	cafe(int **map, int x, int y, int type)
{
  int	cy;
  int	cx;
  int	**tmp;

  cy = 0;
  if (gene_aleatoire(type, &tmp) != 0)
    return (-1);
  while (++cy < 21)
    {
      cx = 0;
      while (++cx < 21)
	map[y * 20 + (cy - 1) + 1][x * 20 + (cx - 1) + 1] = tmp[cy][cx];
    }
  free_grid(tmp);
  return (0);
}

int	**entoure_map(int **map)
{
  int	x;
  int	y;

  y = 0;
  while (y < ((1 * 2) * 20 + 2))
    {
      x = 0;
      while (x < ((1 * 2) * 20 + 2))
	{
	  if (y == 0 || y == 41)
	    map[y][x] = 0;
	  if (x == 0 || x == 41)
	    map[y][x] = 0;
	  x++;
	}
      y++;
    }
  return (map);
}

int	make_map(int **map, int ***map_finale)
{
  int	x;
  int	y;
  int	i;

  i = 0;
  y = 0;
  if (!(*map_finale = malloc((((1 * 2) * 20) + 2) * sizeof(*map_finale))))
    return (1);
  while (i < (((1 * 2) * 20) + 2))
    {
      if (!((*map_finale)[i] = malloc((((1 * 2) * 20) + 2) *
				      sizeof(**map_finale))))
	return (1);
      i++;
    }
  while (map[y] != NULL)
    {
      x = 0;
      while (map[y][x] != -1)
	{
	  if (cafe(*map_finale, x, y, map[y][x]) == -1)
	    return (1);
	  x++;
	}
      y++;
    }
  entoure_map(*map_finale);
  return (0);
}

int	gener_map(int ***map, t_unit **unit)
{
  int	**mapp;
  t_unit	*tmp;

  mapp = malloc(3 * sizeof(*mapp));
  mapp[0] = malloc(3 * sizeof(**mapp));
  mapp[1] = malloc(3 * sizeof(**mapp));
  mapp[2] = NULL;
  mapp[0][0] = 1;
  mapp[0][1] = 1;
  mapp[0][2] = -1;
  mapp[1][0] = 1;
  mapp[1][1] = 1;
  mapp[1][2] = -1;
  tmp = malloc(sizeof(*tmp));
  *unit = tmp;
  tmp->type = 0;
  tmp->hp = 3;
  tmp->pos.x = 320;
  tmp->pos.y = 320;
  tmp->next = NULL;
  make_map(mapp, map);
  return (0);
}

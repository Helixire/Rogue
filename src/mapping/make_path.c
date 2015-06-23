/*
** make_path.c for Rogue in /home/chau_b/projet_ext/Rogue/map
** 
** Made by alexandre chau
** Login   <chau_b@epitech.net>
** 
** Started on  Tue Jun 23 16:52:31 2015 alexandre chau
** Last update Tue Jun 23 18:52:29 2015 alexandre chau
*/

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

void	gene_map(int ***map, t_unit **unit)
{
  int	mapp[3][3];
  t_unit	*tmp;

  tmp = malloc(sizeof(*tmp));
  *unit = tmp;
  tmp->type = 0;
  tmp->hp = 3;
  tmp->pos.x = 320;
  tmp->pos.y = 320;
  tmp->next = NULL;
  mapp[0][0] = 1;
  mapp[0][1] = 1;
  mapp[0][2] = -1;
  mapp[1][0] = 1;
  mapp[1][1] = 1;
  mapp[1][2] = -1;
  mapp[2] = NULL;
  *map = make_map(mapp);
}

int	gene_aleatoire(int type, int ***map)
{
  return (init("map/start", map, NULL));
}

int	cafe(int **map, int x, int y, int type)
{
  int	cy;
  int	cx;
  int	**tmp;

  cy = 0;
  if (!(gene_aleatoire(type, &tmp)))
    return (-1);
  while (++cy < 21)
    {
      cx = 0;
      while (++cx < 21)
	map[y * 20 + (cy - 1)][x * 20 + (cx - 1)] = tmp[cy][cx];
    }
  free_grid(tmp);
  return (0);
}

int	**make_map(int **map)
{
  int	**map_finale;
  int	x;
  int	y;
  int	i;

  i = 0;
  y = 0;
  if (!(map_finale = malloc((((TAILLE_MIN * 2) * 20) + 1) * sizeof(*map_finale))))
    return (NULL);
  while (i < (((TAILLE_MIN * 2) * 20) + 1))
    {
      if (!(map_finale[i] = malloc((((TAILLE_MIN * 2) * 20) + 1) *
				   sizeof(**map_finale))))
	return (NULL);
      i++;
    }
  while (map[y] != NULL)
    {
      x = 0;
      while (map[y][x] != -1)
	{
	  if (cafe(map_finale, x, y, map[y][x]) == -1)
	    return (NULL);
	  x++;
	}
      y++;
    }
  return (map_finale);
}
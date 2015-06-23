/*
** loop.c for game in /home/helixire/rendu/Rogue
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Wed Jun 17 11:02:16 2015 Blank Pierre
** Last update Wed Jun 17 11:02:16 2015 Blank Pierre
*/

#include "game.h"

static int	big(int **grid, int x, int y)
{
  int		i;

  i = 1;
  while (i < y && grid[i][1] != 0)
    i += 1;
  if (i != y || grid[i][1] == 0)
    return (0);
  i = 1;
  while (i < x && grid[1][i] != 0)
    i += 1;
  if (i != x || grid[1][i] == 0)
    return (0);
  return (1);
}

static void	print_map(int **grid, const int xd, const int yd)
{
  int		x;
  int		y;
  SDL_Rect	pos;
  SDL_Rect	size;

  size.y = 0;
  size.w = TSIZE;
  size.h = TSIZE;
  y = -2;
  SDL_FillRect(img[3], NULL, 0);
  while (++y != SIZEY + 1)
    {
      x = -2;
      while (++x != SIZEX + 1)
	{
	  pos.x = (x + 1) * TSIZE;
	  pos.y = (y + 1)  * TSIZE;
	  if (big(grid, x + xd + 1, y + yd + 1) == 1)
	    size.x = (grid[y + yd + 1][x + xd + 1] - 1) * TSIZE;
	  else
	    size.x = TSIZE;
	  SDL_BlitSurface(img[1], &size, img[3], &pos);
	}
    }
}

void		update(int **map, t_unit *unit)
{
  SDL_Rect	tmp;

  print_map(map, unit->pos.x / TSIZE - SIZEX / 2,
	    unit->pos.y / TSIZE - SIZEY / 2);
  tmp.x = - unit->pos.x % TSIZE - TSIZE;
  tmp.y = - unit->pos.y % TSIZE - TSIZE;
  SDL_BlitSurface(img[3], NULL, img[0], &tmp);
  tmp.x = SIZEX * TSIZE / 2;
  tmp.y = SIZEY * TSIZE / 2;
  SDL_BlitSurface(img[2], NULL, img[0], &tmp);
  SDL_Flip(img[0]);
}

int	tiles_at(const int x, const int y, int **grid)
{
  if (x < 0 || y < 0 || grid[y][x] == 0)
    return (2);
  return (grid[y][x]);
}

void	loop(int **map, t_unit *unit)
{
  int		state;
  SDL_Event	event;
  int		ltime;
  int		ctime;
  int		i;

  update(map, unit);
  state = 1;
  ltime = 0;
  while (state)
    {
      while (SDL_PollEvent(&event))
	{
	  if (event.type == SDL_QUIT)
	    state = 0;
	  else if (event.type == SDL_KEYDOWN)
	    {
	      i = -1;
	      while (g_key[++i].active != 2)
		{
		  if (event.key.keysym.sym == g_key[i].key)
		    g_key[i].active = 1;
		}
	    }
	  else if (event.type == SDL_KEYUP)
	    {
	      i = -1;
	      while (g_key[++i].active != 2)
		{
		  if (event.key.keysym.sym == g_key[i].key)
		    g_key[i].active = 0;
		}
	    }
	}
      if (g_key[0].active && !g_key[2].active)
	{
	  if (unit->vy > 0)
	    unit->vy *= 0.9;
	  unit->vy -= 1;
	}
      else if (!g_key[0].active && g_key[2].active)
	{
	  if (unit->vy < 0)
	    unit->vy *= 0.9;
	  unit->vy += 1;
	}
      if (!g_key[0].active && !g_key[2].active)
	unit->vy *= 0.9;
      if ((ABS(unit->vy)) > 20)
	unit->vy = (unit->vy > 0) ? 20 : -20;
      unit->pos.y += unit->vy;
      
      if (g_key[1].active && !g_key[3].active)
	{
	  if (unit->vx > 0)
	    unit->vx *= 0.9;
	  unit->vx -= 1;
	}
      else if (!g_key[1].active && g_key[3].active)
	{
	  if (unit->vx < 0)
	    unit->vx *= 0.9;
	  unit->vx += 1;
	}
      if (!g_key[1].active && !g_key[3].active)
	unit->vx *= 0.9;
      if ((ABS(unit->vx)) > 20)
	unit->vx = (unit->vx > 0) ? 20 : -20;
      unit->pos.x += unit->vx;
      printf("x:%d y:%d\n", ((unit->pos.x - TSIZE)/ TSIZE), (unit->pos.y - TSIZE) / TSIZE);
      update(map, unit);
      if ((ctime = SDL_GetTicks()) - ltime > 1000 / FPS)
	ltime = ctime;
      else
	SDL_Delay(1000 / FPS - (ctime - ltime));
    }
}

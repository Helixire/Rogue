/*
** main.c for game in /home/helixire/rendu/MUL_2014_rtracer
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Tue Jun 16 22:52:50 2015 Blank Pierre
** Last update Tue Jun 16 22:52:50 2015 Blank Pierre
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

static int	game(void)
{
  int		**map;
  t_unit	*unit;

  unit = NULL;
  if (gener_map(&map, &unit) != 0)
    return (1);
  loop(map, unit);
  free_grid(map);
  clean_unit(unit);
  return (0);
}

static int	home(void)
{
  return (game());
}

static int	load(void)
{
  int		ret;

  if (SDL_Init(SDL_INIT_VIDEO) == -1 ||
      (img[0] = SDL_SetVideoMode(SIZEX * TSIZE, SIZEY * TSIZE,
				 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL ||
      (img[1] = IMG_Load("data/tiles.bmp")) == NULL ||
      (img[2] = IMG_Load("data/hero.bmp")) == NULL ||
      (img[3] = SDL_CreateRGBSurface(0, (SIZEX + 2) * TSIZE, (SIZEY + 2) * TSIZE,
				     32, 0, 0, 0, 0)) == NULL ||
      TTF_Init() != 0)
    return (my_error(SDL_GetError()));
  SDL_WM_SetCaption("Rogue", NULL);
  ret = home();
  SDL_FreeSurface(img[0]);
  TTF_CloseFont(g_font);
  TTF_Quit();
  SDL_Quit();
  return (ret);
}

int	main(void)
{
  return (load());
}

/*
** my_sdl.c for game in /home/helixire/rendu/RoleGame/dev
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Mon May 25 04:03:02 2015 Blank Pierre
** Last update Mon May 25 04:03:02 2015 Blank Pierre
*/

#include "game.h"

void	print_str(SDL_Surface *screen, char *str,
		  SDL_Color color, SDL_Rect *pos)
{
  SDL_Surface	*text;

  text = TTF_RenderText_Solid(g_font, str, color);
  SDL_BlitSurface(text, NULL, screen, pos);
  SDL_free(text);
}

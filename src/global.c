/*
** global.c for game in /home/helixire/rendu/RoleGame
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Tue May 26 22:52:18 2015 Blank Pierre
** Last update Tue May 26 22:52:18 2015 Blank Pierre
*/

#include "game.h"

TTF_Font	*g_font;
SDL_Surface	*img[3];
const t_tiles	g_tiles[] = {
  {0, NULL},
  {1, NULL}
};
t_action	g_key[] = {
  {"up", 0, 273},
  {"left", 0, 276},
  {"down", 0, 274},
  {"right", 0, 275},
  {"jump", 0, 32},
  {"END", 2, 0}
};

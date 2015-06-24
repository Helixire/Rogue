/*
** game.h for game in /home/helixire/rendu/RoleGame
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 23 01:55:02 2015 Blank Pierre
** Last update Sat May 23 01:55:02 2015 Blank Pierre
*/

#ifndef _GAME_H_
# define _GAME_H_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <fmod.h>
# include "tool.h"
# include "my_error.h"

# define TSIZE	32

# define SIZEX	26
# define SIZEY	20

# define FPS	60

struct		s_unit
{
  int		type;
  int		hp;
  SDL_Rect	pos;
  int		vx;
  int		vy;
  int		canjump;
  int		jump;
  int		og;
  int		dash;
  struct s_unit	*next;
};

typedef struct	s_action
{
  char		inf[30];
  int		active;
  unsigned int	key;
}		t_action;

typedef struct	s_tiles
{
  int		solid;
  void		(*effect)();
}		t_tiles;

extern TTF_Font		*g_font;
extern SDL_Surface	*img[];
extern t_action		g_key[];
extern const t_tiles	g_tiles[];

int	init(char *file, int ***grid, t_unit **unit);
void	loop(int **map, t_unit *unit);
int	gener_map(int ***map, t_unit **unit);

#endif /* !_GAME_H_ */

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

# define SIZEX	25
# define SIZEY	20

# define BT	BLUE "\rBlue Turn                   \n" NORM
# define RT	RED "\rRed Turn                     \n" NORM

# define NONE	"NONE                                 "
# define END	"\r--end--                          \n"

typedef struct	s_node
{
  SDL_Rect	pos;
  int		dist;
  int		open;
  struct s_node	*next;
}		t_node;

struct		s_unit
{
  int		hp;
  SDL_Rect	pos;
  int		move;
  int		atk;
  int		faction;
  int		type;
  struct s_unit	*next;
};

typedef struct	s_type
{
  char		name[25];
  int		hp;
  int		move;
  int		range;
  int		counter[10];
  int		illegal[20];
}		t_type;

extern TTF_Font		*g_font;
extern SDL_Surface	*img[];
extern int		g_turn;
extern t_unit		*g_sel;
extern FMOD_SYSTEM	*g_m;
extern FMOD_SOUND	*sound[];
extern const t_type	g_type[];

int		init(char *file, int ***grid, t_unit **unit);
void		init_turn(t_unit *list, int *turn);
int		loop_g(int **grid, t_unit **list);
int		can_attack(t_unit *atk, t_unit *def);
void		attack_g(t_unit *atk, t_unit *def, t_unit **);
int		find_path(t_unit *unit, int **grid, t_node **res, t_unit *list);
void		clean_node(t_node **node);
t_node		*node_at(t_node *list, SDL_Rect *pos);

#endif /* !_GAME_H_ */

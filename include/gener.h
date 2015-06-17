/*
** gener.h for game in /home/helixire/rendu/MUL_2014_rtracer
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Tue Jun 16 19:04:00 2015 Blank Pierre
** Last update Tue Jun 16 19:04:00 2015 Blank Pierre
*/

typedef struct	s_room
{
  struct s_room	next[4];
  int		nb;
  int		poid;
  int		state;
  int		used;
}		t_room;


typedef struct	s_list
{
  t_room	*room;
  int		x;
  int		y;
  struct s_list	*list;
}

start
ex1
ex2
ex3
fin

                                 |
                            e1-start-
                             |   |
                               -e2

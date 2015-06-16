/*
** list.c for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 15:23:27 2015 Blank Pierre
** Last update Sat May 16 15:23:27 2015 Blank Pierre
*/

#include <stdlib.h>
#include "my_error.h"
#include "game.h"

int		add_unit(t_unit **list, const int data[4])
{
  t_unit	*ret;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (1);
  ret->type = data[0];
  ret->faction = data[1];
  ret->pos.x = data[2];
  ret->pos.y = data[3];
  ret->hp = g_type[data[0]].hp;
  ret->move = g_type[data[0]].move;
  ret->next = *list;
  *list = ret;
  return (0);
}

void		rm_unit(t_unit **list, t_unit *unit)
{
  t_unit	*tmp;
  t_unit	*i;

  i = *list;
  while (i != NULL && i != unit)
    {
      tmp = i;
      i = i->next;
    }
  if (i != NULL)
    {
      if (i == *list)
	*list = (*list)->next;
      else
	tmp->next = i->next;
      free(i);
    }
}

void		clean_unit(t_unit *list)
{
  t_unit	*tmp;
  t_unit	*tmp2;

  tmp = list;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      free(tmp2);
    }
}

t_unit		*find_unit_at(t_unit *list, const int x, const int y)
{
  t_unit	*i;

  i = list;
  while (i != NULL)
    {
      if (i->pos.x == x && i->pos.y == y)
	return (i);
      i = i->next;
    }
  return (NULL);
}

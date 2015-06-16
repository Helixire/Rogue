/*
** str4.c for game in /home/helixire/rendu/RoleGame
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Tue May 26 09:46:48 2015 Blank Pierre
** Last update Tue May 26 09:46:48 2015 Blank Pierre
*/

#include "tool.h"

int	is_in(const int nb, const int *list)
{
  int	i;

  i = 0;
  while (list[i] != -1)
    {
      if (list[i] == nb)
	return (1);
      i += 1;
    }
  return (0);
}

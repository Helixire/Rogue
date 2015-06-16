/*
** str.c for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 16:07:27 2015 Blank Pierre
** Last update Sat May 16 16:07:27 2015 Blank Pierre
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  (void)write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

void	my_putstr(char *str)
{
  (void)write(2, str, my_strlen(str));
}

int	my_error(char *str)
{
  if (str != NULL)
    (void)write(2, str, my_strlen(str));
  else
    (void)write(2, "ERROR\n", 6);
  return (1);
}

void	my_putnbr(int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

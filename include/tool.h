/*
** tool.h for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 15:25:39 2015 Blank Pierre
** Last update Sat May 16 20:58:12 2015 pinloche antoine
*/

#ifndef _TOOL_H
# define _TOOL_H

# include <SDL/SDL.h>

# define ABS(x)	((x) < 0) ? (-(x)) : (x)

# define SIZE	1024

# define WHITE	"\033[37m"
# define RED	"\033[31m"
# define BLUE	"\033[34m"
# define NORM	"\033[00m"


# define BGGREEN	"\033[42m"
# define SLAIN		" is dead].\n"
# define ATTACK		" as attacked of "
# define HP		" hp now."

typedef struct s_unit t_unit;

int	add_unit(t_unit **list, const int data[4]);
void	rm_unit(t_unit **list, t_unit *unit);
void	clean_unit(t_unit *list);
int	my_getnbr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
int	my_error(char *str);
void	my_putnbr(int nb);
char	*get_next_line(const int fd);
void	my_putstr(char *str);
int	index_of(const char *str, const char c);
char	*my_strndup(char *str, int n);
char	**parse(char *str, char *delim);
int	free_grid(int **grid);
int	free_tab(char **tab);
void	my_putname(char *str);
t_unit	*find_unit_at(t_unit *unit, const int x, const int y);
void	int_to_str(int nb, char str[]);
void	my_revstr(char *str);
void	print_str(SDL_Surface *screen, char *str, SDL_Color, SDL_Rect *pos);
int	is_in(const int nb, const int *list);

#endif /* !_TOOL_H */

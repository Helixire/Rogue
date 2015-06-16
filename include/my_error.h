/*
** my_error.h<BocalEmblem> for emblem in /home/helixire/rendu/PSU_2014_42sh
** 
** Made by Blank Pierre
** Login   <blank_p@epitech.net>
** 
** Started on  Sat May 16 16:00:09 2015 Blank Pierre
** Last update Sat May 16 16:00:09 2015 Blank Pierre
*/

#ifndef _MY_ERROR_H
# define _MY_ERROR_H

# define NF	"Please enter a file in param(map/0.map)\n"
# define WF	"Wrong format for map\n"
# define NU	"No unit on the map\n"
# define GS	"Grid too small\n"
# define EO	"Error open\n"
# define EM	"ERROR MALLOC\n"
# define UE	"ERROR 2 units with the same id\n"
# define GE	"An error occured\n"
# define FE	"File is existing\nExtension is OK.\n"
# define WD	"Wrong direction (top, bottom, left, right)\n"
# define NA	"Cannot go here\n"
# define UNF	"Unit not found\n"
# define CNF	"Command not found (help)\n"
# define UAM	"Unit already moved\n"

int	my_error(char *str);

#endif /* !_MY_ERROR_H */

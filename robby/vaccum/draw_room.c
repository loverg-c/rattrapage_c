/*
** draw_room.c for draw_room in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 24 14:29:13 2013 clement lovergne
** Last update Mon Jun 24 14:30:34 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

char		**malloc_room(char **room)
{
  int		i;
  int		j;

  if ((room = malloc(24 * sizeof(char*))) == NULL)
    error_message("malloc");
  room[23] = NULL;
  i = 0;
  while (i < 23)
    {
  j = 0;
      if ((room[i] = malloc(24 * sizeof(char))) == NULL)
	error_message("malloc");
      while (j <= 23)
	{
	  room[i][j] = '\0';
	  j++;
	}
      i++;
    }
  return (room);
}

char		**draw_room(t_vaccum *vaccum)
{
  char		**room;
  int		i;
  int		j;

  room = NULL;
  room = malloc_room(room);
  i = -1;
  while (++i <= 22)
    {
      room[0][i] = '-';
      room[22][i] = '-';
    }
  i = 0;
  while (++i < 22)
    {
      j = 0;
      room[i][0] = '|';
      room[i][22] = '|';
      while (++j < 22)
	room[i][j] = ' ';
    }
  return (room);
}

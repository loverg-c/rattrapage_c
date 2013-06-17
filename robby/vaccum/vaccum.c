/*
** vaccum.c for vaccum in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:28:56 2013 clement lovergne
** Last update Mon Jun 17 21:54:31 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

static char	**malloc_room(char **room)
{
  int		i;

  if ((room = malloc(24 * sizeof(char*))) == NULL)
    error_message("malloc");
  room[23] = NULL;
  i = 0;
  while (i < 23)
    {
      if ((room[i] = malloc(24 * sizeof(char))) == NULL)
	error_message("malloc");
      room[i][23] = '\0';
      i++;
    }
  return (room);
}

static char	**draw_room(t_vaccum *vaccum)
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

static void	init_vaccum(t_vaccum *vaccum)
{
  vaccum->robby_x = 10;
  vaccum->robby_y = 10;
  vaccum->dab_x = 0;
  vaccum->dab_y = 0;
  vaccum->old_robby_x = 10;
  vaccum->old_robby_y = 10;
  vaccum->old_dab_x = 0;
  vaccum->old_dab_y = 0;
  vaccum->old_values = ' ';
}

void		go_to_vaccum(char **mouv)
{
  char		**room;
  t_vaccum	vaccum;
  int		i;

  i = 0;
  room = draw_room(&vaccum);
  init_vaccum(&vaccum);
  replace_maps(room, &vaccum);
  while (mouv[i])
    {
      try_to_mouv(mouv, &vaccum, room, i);
      i++;
    }
  free_all(room);
  sleep(3);
}

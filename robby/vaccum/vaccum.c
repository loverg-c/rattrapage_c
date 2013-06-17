/*
** vaccum.c for vaccum in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:28:56 2013 clement lovergne
** Last update Mon Jun 17 19:27:41 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

static char	**malloc_room(char **room)
{
  int		i;

  if ((room = malloc(23 * sizeof(char*))) == NULL)
    error_message("malloc");
  room[22] = NULL;
  i = 0;
  while (i < 22)
    {
      if ((room[i] = malloc(23 * sizeof(char))) == NULL)
	error_message("malloc");
      room[i][22] = '\0';
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
  while (++i <= 21)
    {
      room[0][i] = '-';
      room[21][i] = '-';
    }
  i = 0;
  while (++i < 21)
    {
      j = 0;
      room[i][0] = '|';
      room[i][21] = '|';
      while (++j < 21)
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

static void	replace_maps(char **room, t_vaccum *vaccum)
{
  if (vaccum->old_values != 'o')
    room[vaccum->old_dab_y + 1][vaccum->old_dab_x + 1] = ' ';
  else
    room[vaccum->old_dab_y + 1][vaccum->old_dab_x + 1] = 'o';
  room[vaccum->old_robby_y + 1][vaccum->old_robby_x + 1] = ' ';
  room[vaccum->robby_y + 1][vaccum->robby_x + 1] = 'R';
  room[vaccum->dab_y + 1][vaccum->dab_x + 1] = 'D';
}

void		go_to_vaccum()
{
  char		**room;
  int		i;
  t_vaccum	vaccum;

  i = 0;
  room = draw_room(&vaccum);
  init_vaccum(&vaccum);
  replace_maps(room, &vaccum);
  while (room[i])
    {
      my_putstr(room[i]);
      my_putchar('\n');
      i++;
    }
  free_all(room);
  sleep(3);
}

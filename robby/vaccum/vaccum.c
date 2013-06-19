/*
** vaccum.c for vaccum in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:28:56 2013 clement lovergne
** Last update Wed Jun 19 13:41:58 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

static char	**malloc_room(char **room)
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

static char	**init_vaccum(t_vaccum *vaccum, int *save_cycle, int *i)
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
  vaccum->nb_cycle = 0;
  *save_cycle = 0;
  vaccum->nb_choose = 0;
  *i = 0;
  return (draw_room(vaccum));
}

int		search_o(char **maps)
{
  int		x;
  int		y;
  int		count;

  y = 0;
  count = 0;
  while (maps[y])
    {
      x = 0;
      while (maps[y][x])
	{
	  if (maps[y][x] == 'o')
	    count++;
	  x++;
	}
      y++;
    }
  return (count);
}

static void	do_rooby(int *save_cycle, t_vaccum *vaccum, char **room)
{
  my_robby(save_cycle, vaccum);
  replace_maps(room, vaccum);
}

void		go_to_vaccum(char **mouv)
{
  char		**room;
  t_vaccum	vaccum;
  int		i;
  int		o;
  int		save_cycle;

  room = init_vaccum(&vaccum, &save_cycle, &i);
  replace_maps(room, &vaccum);
  while (mouv[i] || search_o(room) != 0)
    {
      vaccum.map = room;
      while (mouv[i])
	{
	  vaccum.map = room;
	  if ((o = try_to_mouv(mouv, &vaccum, room, i)) == 1)
	    i++;
	  do_rooby(&save_cycle, &vaccum, room);
	  if (o == 1 && mouv[i] != NULL)
	    vaccum.old_values = 'o';
	}
      do_rooby(&save_cycle, &vaccum, room);
    }
  free_all(room);
  sleep(3);
}

/*
** display_vaccum.c for display_vaccum in /home/loverg_c//RATTRAPAGE/rattrapage_c/robby/vaccum
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 20:57:19 2013 clement lovergne
** Last update Tue Jun 18 02:34:02 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

void		replace_maps(char **room, t_vaccum *vaccum)
{
  if (vaccum->old_values != 'o')
    room[vaccum->old_dab_y + 1][vaccum->old_dab_x + 1] = ' ';
  else
    room[vaccum->old_dab_y + 1][vaccum->old_dab_x + 1] = 'o';
  room[vaccum->old_robby_y + 1][vaccum->old_robby_x + 1] = ' ';
  vaccum->old_values = room[vaccum->dab_y + 1][vaccum->dab_x + 1];
  room[vaccum->robby_y + 1][vaccum->robby_x + 1] = 'R';
  room[vaccum->dab_y + 1][vaccum->dab_x + 1] = 'D';
  if (system("clear") == -1)
    error_message("system");
  my_putstr2(room);
  my_putstr("Nombre de cycle : ");
  my_putnbr(vaccum->nb_cycle);
  vaccum->nb_cycle++;
  usleep(100000);
}

static void	move_my_dab(t_vaccum *vaccum, int x, int y)
{
  vaccum->old_dab_x = vaccum->dab_x;
  vaccum->old_dab_y = vaccum->dab_y;
  if (vaccum->dab_x < x)
    vaccum->dab_x++;
  else if (vaccum->dab_x > x)
    vaccum->dab_x--;
  else
    {
      if (vaccum->dab_y < y)
	vaccum->dab_y++;
      else if (vaccum->dab_y > y)
	vaccum->dab_y--;
    }
}

static char	*get_x(char *str, int *i, char *tmpx, int *j)
{
  while (str[*i] != ';')
    *i += 1;
  if ((tmpx = malloc((*i + 1) * sizeof(char))) == NULL)
    error_message("malloc");
  tmpx[*i] = '\0';
  while (*j < *i)
    {
      tmpx[*j] = str[*j];
      *j += 1;
    }
  return (tmpx);
}

static char	*get_y(char *str, int *i, char *tmpy, int *j)
{
  if ((tmpy = malloc((my_strlen(str) - *i) * sizeof(char))) == NULL)
    error_message("malloc");
  tmpy[my_strlen(str) - *i - 1] = '\0';
  *i += 1;
  while (*j < my_strlen(str))
    {
      tmpy[*j] = str[*i];
      *i += 1;
      *j += 1;
    }
  return (tmpy);
}

int		try_to_mouv(char **str, t_vaccum *vaccum, char **room, int k)
{
  int		i;
  int		j;
  char		*tmpx;
  char		*tmpy;
  int		value;

  value = 0;
  j = 0;
  i = 0;
  tmpx = NULL;
  tmpy = NULL;
  tmpx = get_x(str[k], &i, tmpx, &j);
  j = 0;
  tmpy = get_y(str[k], &i, tmpy, &j);
  move_my_dab(vaccum, atoi(tmpx), atoi(tmpy));
  if (vaccum->dab_x == atoi(tmpx) && vaccum->dab_y == atoi(tmpy))
    value = 1;
  free(tmpx);
  free(tmpy);
  return (value);
}

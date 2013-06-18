/*
** robby_and_vaccum.c for robbb_and_vaccum in /home/loverg_c//RATTRAPAGE/rattrapage_c/robby/vaccum
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 23:33:07 2013 clement lovergne
** Last update Tue Jun 18 03:06:52 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"


static int	check_mvt(t_vaccum *vaccum, int test_mvt, int *xs, int *ys)
{
  int		x;
  int		y;
  int		minx;
  int		miny;
  int		maxy;
  int		maxx;

  minx = (vaccum->robby_x - test_mvt > 0 ? vaccum->robby_x - test_mvt : 0);
  maxx = (vaccum->robby_x + test_mvt < 22 ? vaccum->robby_x + test_mvt : 22);
  miny = (vaccum->robby_y - test_mvt > 0 ? vaccum->robby_y - test_mvt : 0);
  maxy = (vaccum->robby_y + test_mvt < 22 ? vaccum->robby_y + test_mvt : 22);
  x = minx;
  y = miny;
  while (vaccum->map[y] != NULL && y < maxy)
    {
      if (vaccum->map[y + 1][x + 1] == 'o' && vaccum->map[y + 1][x + 1])
	{
	  *xs = x;
	  *ys = y;
	  return (1);
	}
      else
	{
	  if (x <= maxx && vaccum->map[y][x + 1])
	    x += 1;
	  else
	    {
	      x = minx;
	      y += 1;
	    }
	}
    }
  return (0);
}

static void	calc_where(t_vaccum *vaccum, int *x, int *y, int i)
{
  int		test_mvt;

  if (i == 0)
    {
      *x = vaccum->dab_x;
      *y = vaccum->dab_y;
    }
  else
    {
      test_mvt = 1;
      while (check_mvt(vaccum, test_mvt, x, y) == 0)
	test_mvt++;
    }
}

void		my_robby(int *save_cycle, t_vaccum *vaccum)
{
  int		i;
  int		cible_x;
  int		cible_y;

  if (*save_cycle == (vaccum->nb_cycle - vaccum->nb_choose) || *save_cycle == 0)
    {
      vaccum->old_robby_x = vaccum->robby_x;
      vaccum->old_robby_y = vaccum->robby_y;
      if (vaccum->robby_y == 0)
	vaccum->robby_y = 1;
      if (vaccum->robby_x == 0)
	vaccum->robby_x = 1;
      *save_cycle = vaccum->nb_cycle;
      i = (search_o(vaccum->map) == 0 ? 0 : 1);
      calc_where(vaccum, &cible_x, &cible_y, i);
      if (cible_x == vaccum->robby_x || cible_y == vaccum->robby_y)
	{
	  vaccum->nb_choose = 2;
	  if (cible_x == vaccum->robby_x)
	    vaccum->robby_y = (vaccum->robby_y - cible_y < 0 ?
			       vaccum->robby_y + 1 : vaccum->robby_y - 1);
	  else
	    vaccum->robby_x = (vaccum->robby_x - cible_x < 0 ?
			       vaccum->robby_x + 1 : vaccum->robby_x - 1);
	}
      else
	{
	  vaccum->nb_choose = 3;
	  vaccum->robby_y = (vaccum->robby_y - cible_y < 0 ?
			     vaccum->robby_y + 1 : vaccum->robby_y - 1);
	  vaccum->robby_x = (vaccum->robby_x - cible_x < 0 ?
			     vaccum->robby_x + 1 : vaccum->robby_x - 1);
	}
    }

}
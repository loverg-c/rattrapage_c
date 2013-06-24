/*
** sub.c for sub in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun 23 15:41:10 2013 clement lovergne
** Last update Sun Jun 23 15:55:12 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

static void	do_the_sub(char **frigo, char *afterpc, int *j1, int *i)
{
  int		a;

  a = my_strlen(afterpc) - 1;
  while (a >= 0)
    {
      if (afterpc[a] > '9')
	{
	  frigo[*i][*j1] -= 1;
	  afterpc[a] -= 10;
	}
      if (frigo[*i][*j1] - afterpc[a] < 0)
	{
	  frigo[*i][*j1] += 10;
	  frigo[*i][*j1 - 1] -= 1;
	}
      frigo[*i][*j1] -= afterpc[a];
      frigo[*i][*j1] += 48;
      *j1 -= 1;
      a--;
    }
}

static void	sub_2(char *ingredient, char **frigo, int *i)
{
  int		j1;
  char		*afterpc1;

  while (frigo[*i] && frigo[*i][0])
    {
      if (my_strncmp(ingredient, frigo[*i],
		     go_to_pc(ingredient)) == 0)
	{
	  j1 = go_to_pc(ingredient) + 1;
	  afterpc1 = copy_afterpc(&j1, ingredient);
	  j1 = my_strlen(frigo[*i]) - 1;
	  do_the_sub(frigo, afterpc1, &j1, i);
	}
      *i += 1;
    }
  free(afterpc1);
}

void		sub(char *ingredient, char **frigo, t_list_rec **recette)
{
  int		i;
  t_list_rec	*elem;
  int		b;

  elem = *recette;
  while (my_strncmp(ingredient, elem->recettes, go_to_pc(ingredient)) != 0)
    elem = elem->next;
  b = 0;
  while (elem->ingredient[b])
    {
      i = 0;
      sub_2(elem->ingredient[b], frigo, &i);
      b++;
    }
}

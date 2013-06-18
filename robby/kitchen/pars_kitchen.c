/*
** pars_kitchen.c for pars_kitchen in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue Jun 18 12:14:35 2013 clement lovergne
** Last update Tue Jun 18 12:23:49 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

static char	*copy_afterpc(int *j, char *recettes)
{
  int		i;
  char		*afterpc;

  i = 0;
  if ((afterpc = malloc(my_strlen(recettes) - *j)) == NULL)
    error_message("malloc");
  while (recettes[*j])
    {
      afterpc[i] = recettes[*j];
      i++;
      *j += 1;
    }
  afterpc[i] = '\0';
  if (i == 0)
    error_message(" : In frigo/recettes_Robby : line with nothing after \';\'");
  return (afterpc);
}

static int	check_afterpcomakitchen(char *recettes, int *j)
{
  char		*afterpc;
  int		i;
  int		count;

  count = 0;
  afterpc = copy_afterpc(j, recettes);
  if (my_strcmp(afterpc, "entree") != 0 && my_strcmp(afterpc, "plat") != 0 &&
      my_strcmp(afterpc, "dessert") != 0)
    {
      i = 0;
      while (afterpc[i])
	{
	  if (afterpc[i] < '0' || afterpc[i] > '9')
	    error_message(" : In frigo/recettes_Robby : mistake after a \';\'");
	  i++;
	}
    }
  else
    count = 1;
  free(afterpc);
  return (count);
}

void		check_validfrigo(char **frigo)
{
  int		i;
  int		j;

  i = -1;
  while (frigo[++i])
    {
      j = 0;
      my_putchar('\n');
      if (count_pointcoma(frigo[i]) != 1)
	error_message(" : In frigo_Robby : mistake with \';\'");
      while (frigo[i][j] != ';')
	j++;
      j++;
     check_afterpcomakitchen(frigo[i], &j);
    }
}

void		check_validrecette(char **recettes)
{
  int		i;
  int		j;
  int		count;

  count = 0;
  i = -1;
  while (recettes[++i])
    {
      j = 0;
      my_putchar('\n');
      if (count_pointcoma(recettes[i]) != 1)
	error_message(" : In recettes_Robby : mistake with \';\'");
      while (recettes[i][j] != ';')
	j++;
      j++;
      count += check_afterpcomakitchen(recettes[i], &j);
    }
  if (count == 0)
    error_message(" : In recettes_Robby : No recipes !");
}

/*
** pars_kitchen.c for pars_kitchen in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue Jun 18 12:14:35 2013 clement lovergne
** Last update Sun Jun 23 16:30:44 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

char		*copy_afterpc(int *j, char *recettes)
{
  int		i;
  char		*afterpc;

  i = 0;
  if ((afterpc = malloc(my_strlen(recettes) - *j + 1)) == NULL)
    error_message("malloc");
  while (recettes[*j])
    {
      afterpc[i] = recettes[*j];
      i++;
      *j += 1;
    }
  afterpc[i] = '\0';
  if (i == 0)
    error_message(": In frigo/recettes_Robby: line with nothing after \';\'");
  return (afterpc);
}

static int	check_afterpcomakitchen(char *recettes, int *j)
{
  char		*afterpc;
  int		i;
  int		count;

  count = 0;
  afterpc = copy_afterpc(j, recettes);
  if (my_strcmp(afterpc, "entree") != 0 &&
      my_strcmp(afterpc, "plat") != 0 &&
      my_strcmp(afterpc, "dessert") != 0)
    {
      i = 0;
      while (afterpc[i])
	{
	  if (afterpc[i] < '0' || afterpc[i] > '9')
	    error_message(": In frigo/recettes_Robby: mistake after a \';\'");
	  i++;
	}
      if (atoi(afterpc) <= 0)
	error_message("frigo : one ingredient is null or neg");
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
  int		a;

  i = -1;
  while (++i < my_strlen2(frigo) && frigo[i][0])
    {
      my_putchar('\n');
      if (count_pointcoma(frigo[i]) != 1)
	error_message(" : In frigo_Robby : mistake with \';\'");
      j = go_to_pc(frigo[i]) + 1;
     check_afterpcomakitchen(frigo[i], &j);
     a = 0;
     while (a < my_strlen2(frigo) && frigo[a][0])
       {
	 if (my_strncmp(frigo[i], frigo[a], j) == 0 && a != i)
	    error_message("frigo: 2 * the same ingredient(add them between)");
	 a++;
       }
    }
}

void		check_validrecette(char **recettes)
{
  int		i;
  int		j;
  int		count;

  count = 0;
  i = -1;
  while (++i < my_strlen2(recettes) && recettes[i][0])
    {
      my_putchar('\n');
      if (count_pointcoma(recettes[i]) != 1)
	error_message(" : In recettes_Robby : mistake with \';\'");
      j = go_to_pc(recettes[i]) + 1;
      count += check_afterpcomakitchen(recettes[i], &j);
    }
  if (count == 0)
    error_message(" : In recettes_Robby : No recipes !");
}

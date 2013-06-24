/*
** count_ingredients.c for count_ingredients in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Thu Jun 20 13:43:14 2013 clement lovergne
** Last update Sun Jun 23 16:02:36 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

void		display_choose(char **choose)
{
  int		i;

  i = 0;
  while (choose[i])
    {
      my_putnbr(i);
      my_putstr(" - ");
      my_putstr(choose[i]);
      if (choose[i + 1])
	my_putstr(", ");
      i++;
    }
}

int		my_strncmp(char *str, char *cmp, int t)
{
  int		i;

  i = 0;
  while (i < t)
    {
      if (str[i] != cmp[i])
	return (1);
      i++;
    }
  return (0);
}

static int	search_and_count(char *ingredient, char **frigo)
{
  int		i;
  char		*afterpc1;
  char		*afterpc2;
  int		j1;
  int		j2;

  i = 0;
  while (frigo[i] && frigo[i][0])
    {
      if (my_strncmp(ingredient, frigo[i], go_to_pc(ingredient)) == 0)
	{
	  j1 = go_to_pc(ingredient) + 1;
	  j2 = go_to_pc(frigo[i]) + 1;
	  afterpc1 = copy_afterpc(&j1, ingredient);
	  afterpc2 = copy_afterpc(&j2, frigo[i]);
	  if (atoi(afterpc1) <= atoi(afterpc2))
	    return (1);
	}
      i++;
    }
  return (0);
}

static int	count_ingredient(char **ingredient, char **frigo)
{
  int		i;
  int		good;

  i = 0;
  good = 1;
  while (ingredient[i] && good == 1)
    {
      good = search_and_count(ingredient[i], frigo);
      i++;
    }
  return (good);
}

char		**choose_entree(t_list_rec **entree, char **frigo)
{
  t_list_rec	*elem;
  char		**choose;

  if ((choose = malloc(1 * sizeof(char*))) == NULL)
    error_message("malloc");
  choose[0] = NULL;
  elem = *entree;
  while (elem != NULL)
    {
      if (count_ingredient(elem->ingredient, frigo) == 1)
	choose = my_copy_line(choose, elem->recettes);
      elem = elem->next;
    }
  elem = *entree;
  if (choose[0] == NULL)
    {
      my_putstr("Sorry I havn't ingredient for do : ");
      my_putstr(elem->type);
    }
  return (choose);
}

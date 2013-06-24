/*
** check_types.c for check_types in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri Jun 21 18:20:49 2013 clement lovergne
** Last update Sun Jun 23 20:40:00 2013 clement lovergne
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"../../dot_h/fonction.h"

void		check_rec(char **rec)
{
  int		i;
  int		j;
  char		*afterpc;

  i = 0;
  while (rec[i] && rec[i][0])
    {
      j = go_to_pc(rec[i]) + 1;
      afterpc = copy_afterpc(&j, rec[i]);
      if (my_strcmp(afterpc, "entree") == 0 || my_strcmp(afterpc, "plat") == 0
	  || my_strcmp(afterpc, "dessert") == 0)
	{
	  if (rec[i + 1] && rec[i + 1][0])
	    {
	      j = go_to_pc(rec[i + 1]) + 1;
	      afterpc = copy_afterpc(&j, rec[i + 1]);
	    }
	  if (my_strcmp(afterpc, "entree") == 0 ||
	      my_strcmp(afterpc, "plat") == 0 ||
	      my_strcmp(afterpc, "dessert") == 0 || !(rec[i + 1]))
	    error_message(": in recettes : no ingredients");
	}
      i++;
    }
  free(afterpc);
}

static void		stock_type(t_list_rec **rec,
				   t_list_rec **list_entree, int j)
{
  int			i;
  t_list_rec		*elem1;
  t_list_rec		*elem2;

  elem1 = *rec;
  elem2 = NULL;
  elem2 = malloc_list(sizeof (t_list_rec));
  i = 0;
  while (elem1 != NULL && i != j)
    {
      elem1 = elem1->next;
      i++;
    }
  elem2->recettes = elem1->recettes;
  elem2->type = elem1->type;
  elem2->ingredient = elem1->ingredient;
  elem2->next = *list_entree;
  *list_entree = elem2;
}

void    	check_type(t_list_rec **rec, t_list_rec **list_dessert,
			      t_list_rec **list_entree, t_list_rec **list_plat)
{
  t_list_rec	*elem;
  int		j;

  j = 0;
  elem = malloc_list(sizeof (t_list_rec));
  elem = *rec;
  while (elem != NULL)
    {
      if (my_strcmp(elem->type, "entree") == 0)
	  stock_type(rec, list_entree, j);
      else if (my_strcmp(elem->type, "plat") == 0)
	  stock_type(rec, list_plat, j);
      else if (my_strcmp(elem->type, "dessert") == 0)
	  stock_type(rec, list_dessert, j);
      j++;
      elem = elem->next;
    }
}

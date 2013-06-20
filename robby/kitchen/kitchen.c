/*
** kitchen.c for kitchen in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:34:14 2013 clement lovergne
** Last update Wed Jun 19 20:21:36 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

int		go_to_pc(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ';')
    i++;
  return (i);
}

static void	my_aff_list(t_list_rec **list_rec)
{
  t_list_rec *elem;

  elem = *list_rec;
  while (elem != NULL)
    {
      my_putstr("recettes   : ");
      my_putstr(elem->recettes);
      my_putstr(" - ");
      my_putstr(elem->type);
      my_putstr("\ningredients : ");
      my_putstr2(elem->ingredient);
      my_putchar('\n');
      elem = elem->next;
    }
}

static t_list_rec	*do_list(char **recettes)
{
  t_list_rec	*list_rec;
  int		i;
  int		j;
  char		*afterpc;

  i = 0;
  list_rec = NULL;
  while (recettes[i] && recettes[i][0] != '\0')
    {
      j = go_to_pc(recettes[i]);
      j++;
      afterpc = copy_afterpc(&j, recettes[i]);
      if (my_strcmp(afterpc, "entree") == 0 ||
	  my_strcmp(afterpc, "plat") == 0 ||
	  my_strcmp(afterpc, "dessert") == 0)
	my_putinlist(&list_rec, recettes, &i);
      else
	i++;
    }
  return (list_rec);
}

static void	check_rec(char **rec)
{
  int		i;
  int		j;
  char		*afterpc;

  i = 0;
  while (rec[i] && rec[i][0])
    {
      j = go_to_pc(rec[i]) + 1;
      afterpc = copy_afterpc(&j, rec[i]);
      if (my_strcmp(afterpc, "entree") == 0 ||
	  my_strcmp(afterpc, "plat") == 0 ||
	  my_strcmp(afterpc, "dessert") == 0)
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
}

static void		stock_entree(t_list_rec **rec, t_list_rec **list_entree, int j)
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

static void    	check_entree(t_list_rec **rec, t_list_rec **list_dessert,
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
	  stock_entree(rec, list_entree, j);
      else if (my_strcmp(elem->type, "plat") == 0)
	  stock_entree(rec, list_plat, j);
      else if (my_strcmp(elem->type, "dessert") == 0)
	  stock_entree(rec, list_dessert, j);
      j++;
      elem = elem->next;
    }
}

void		go_to_kitchen(char **frigo, char **recettes)
{
  t_list_rec	*list_rec;
  t_list_rec	*entree;
  t_list_rec	*dessert;
  t_list_rec	*plat;

  check_rec(recettes);
  list_rec = do_list(recettes);
  my_aff_list(&list_rec);
  entree = malloc_list(sizeof (t_list_rec));
  entree = NULL;
  dessert = malloc_list(sizeof (t_list_rec));
  dessert = NULL;
  plat = malloc_list(sizeof (t_list_rec));
  plat = NULL;
  check_entree(&list_rec, &entree, &dessert, &plat);
  sleep(3);
}

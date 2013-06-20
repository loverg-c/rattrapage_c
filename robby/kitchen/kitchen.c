/*
** kitchen.c for kitchen in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:34:14 2013 clement lovergne
** Last update Thu Jun 20 15:22:14 2013 clement lovergne
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

/*static void	my_aff_list(t_list_rec **list_rec)
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
    }*/

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

static void		stock_type(t_list_rec **rec, t_list_rec **list_entree, int j)
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

static void    	check_type(t_list_rec **rec, t_list_rec **list_dessert,
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

static int	again_choose()
{
  char		*awns;
  int		i;

  if ((awns = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  all_to_zero(awns, 4096);
  if ((i = read(0, awns, 4096)) == -1)
    error_message("read");
  my_putchar('\n');
  awns[i - 1] = '\0';
  i = 0;
  if (my_strcmp(awns, "yes") == 0)
    i = 1;
  if (my_strcmp(awns, "no") == 0)
    i = 2;
  free(awns);
  return (i);
}

static int	what_he_choose()
{
  char		*awns;
  int		i;
  int		a;

  a = 0;
  if ((awns = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  all_to_zero(awns, 4096);
  if ((i = read(0, awns, 4096)) == -1)
    error_message("read");
  my_putchar('\n');
  awns[i - 1] = '\0';
  i = 0;
  while (awns[i] && a != -1)
    {
      if (awns[i] > '9' || awns[i] < '0')
	a = -1;
      i++;
    }
  if (a != -1)
    a = atoi(awns);
  free(awns);
  return (a);
}

static int	do_the_choose(char **str)
{
  int		a;

  a = what_he_choose();
  while (a < 0 || a > my_strlen2(str) - 1)
    {
      my_putstr("Bad choice\n\n");
      display_choose(str);
      my_putstr("\n\n");
      a = what_he_choose();
    }
  my_putstr("You choose : ");
  my_putstr(str[a]);
  my_putstr("\n\n");
  a = 0;
  while (a == 0)
    {
      my_putstr("Do you want to change it ? (yes or no)\n");
      a = again_choose();
    }
  return (a);
}

void		go_to_kitchen(char **frigo, char **recettes)
{
  t_list_rec	*list_rec;
  t_list_rec	*entree;
  t_list_rec	*dessert;
  t_list_rec	*plat;
  int		again;
  char		**str;

  again = 1;
  check_rec(recettes);
  list_rec = do_list(recettes);
  entree = malloc_list(sizeof (t_list_rec));
  entree = NULL;
  dessert = malloc_list(sizeof (t_list_rec));
  dessert = NULL;
  plat = malloc_list(sizeof (t_list_rec));
  plat = NULL;
  check_type(&list_rec, &dessert, &entree, &plat);
  while (again == 1)
    {
      str = choose_entree(&entree, frigo);
      my_putstr("Entree disponible :\n");
      display_choose(str);
      my_putstr("\n\n");
      again = do_the_choose(str);
    }
  free_all(str);
  sleep(1);
}

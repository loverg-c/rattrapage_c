/*
** kitchen.c for kitchen in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:34:14 2013 clement lovergne
** Last update Fri Jun 21 14:00:00 2013 clement lovergne
*/

#include	<string.h>
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

t_list_rec	*do_list(char **recettes)
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
  free(afterpc);
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
  return (a);
}

static int	choose_this(t_list_rec **entree, char **frigo, char **str)
{
  t_list_rec	*elem;
  int		a;

  a = -1;
  elem = *entree;
  if (str[0])
    {
      my_putstr(elem->type);
      my_putstr(" availible :\n");
      display_choose(str);
      my_putstr("\n\n");
      a = do_the_choose(str);
    }
  return (a);
}

static void	sub(char *ingredient, char **frigo, t_list_rec **recette)
{
  int		i;
  char		*afterpc1;
  int		j1;
  int		a;
  t_list_rec	*elem;
  int		b;

  elem = *recette;
  while (my_strncmp(ingredient, elem->recettes, go_to_pc(ingredient)) != 0)
    elem = elem->next; 
  b = 0;
  while (elem->ingredient[b])
    {
      i = 0;
      while (frigo[i] && frigo[i][0])
	{
	  if (my_strncmp(elem->ingredient[b], frigo[i], go_to_pc(elem->ingredient[b])) == 0)
	    {
	      j1 = go_to_pc(elem->ingredient[b]) + 1;
	      afterpc1 = copy_afterpc(&j1, elem->ingredient[b]);
	      a = my_strlen(afterpc1) - 1;
	      j1 = my_strlen(frigo[i]) - 1;
	      while (a >= 0)
		{
		  if (afterpc1[a] > '9')
		    {
		      frigo[i][j1] -= 1;
		      afterpc1[a] -= 10;
		    }
		  if (frigo[i][j1] - afterpc1[a] < 0)
		    {
		      frigo[i][j1] += 10;
		      frigo[i][j1 - 1] -= 1;
		    }
		  frigo[i][j1] -= afterpc1[a];
		  frigo[i][j1] += 48;
		  j1--;
		  a--;
		}
	    }
	  i++;
	}
      b++;
    }
  free(afterpc1);
}

static int	menu2(t_list_rec **entree, t_list_rec **plat,
		      t_list_rec **dessert, char **frigo)
{
  char		**str;
  int		again;

  str = choose_entree(entree, frigo);
  again = choose_this(entree, frigo, str);
  if (again != -1)
    sub(str[again], frigo, entree);
  str = choose_entree(plat, frigo);
  again = choose_this(plat, frigo, str);
  if (again != -1)
    sub(str[again], frigo, plat);
  str = choose_entree(dessert, frigo);
  again = choose_this(dessert, frigo, str);
  if (again != -1)
    sub(str[again], frigo, dessert);
  again = 0;
  while (again == 0)
    {
      my_putstr("\n\nDo you want to change it ? (yes or no)\n");
      again = again_choose();
    }
  free_all(str);
  return (again);
}

static char	**my_copy(char **frigo)
{
  int		i;
  char		**tmp;

  i = 0;
  if ((tmp = malloc((my_strlen2(frigo) + 1) * sizeof(char*))) == NULL)
    error_message("malloc");
  tmp[my_strlen2(frigo)] = NULL;
  while (i < my_strlen2(frigo) + 1)
    {
      if ((tmp[i] = malloc((my_strlen(frigo[i]) + 1) * sizeof(char))) == NULL)
	  error_message("malloc");
      i++;
    }
  i = 0;
  while (frigo[i][0] && frigo[i])
    {
      tmp[i] = strdup(frigo[i]);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

void		go_to_kitchen(t_file *file, t_all *all)
{
  int		again;
  char		**tmp1;

  tmp1 = NULL;
  again = 0;
  while (again == 0 || again == 1)
    {
      tmp1 = my_copy(file->frigo);
      again = menu2(&all->entree, &all->plat, &all->dessert, tmp1);
      free_all(tmp1);
    }
  sleep(1);
}

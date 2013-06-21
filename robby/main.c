/*
** main.c for Robby in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:25:57 2013 clement lovergne
** Last update Fri Jun 21 14:22:18 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../dot_h/fonction.h"

static void	display(int *error, char *awns)
{
  if (system("clear") == -1)
    error_message("clear");
  if (*error == 1)
    {
      my_putstr(awns);
      my_putstr(" : it's not a good choice\n\n");
    }
  my_putstr("Welcome in Robby's interface !");
  my_putstr(" You can enter 1, 2, 3 or 4 depending on your ");
  my_putstr("choice :\n\n1 - Telephone\n\n2 - Vaccum\n\n");
  my_putstr("3 - Kitchen\n\n4 - Shutdown Robby\n\n");
}

static void	shut_down()
{
  my_putstr("Good Bye !\n\n");
  exit(0);
}

static void	menu(char *awns, t_file *file, t_all *all)
{
  int		i;
  int		error;

  while (42)
    {
      display(&error, awns);
      all_to_zero(awns, 4096);
      error = 0;
      if ((i = read(0, awns, 4096)) == -1)
       	error_message("read");
      my_putchar('\n');
      awns[i - 1] = '\0';
      if (my_strcmp(awns, "1") == 0)
	stay_on_phone(file->wtd, file->com);
      else if (my_strcmp(awns, "2") == 0)
	go_to_vaccum(file->mouv_dab);
      else if (my_strcmp(awns, "3") == 0)
	go_to_kitchen(file, all);
      else if (my_strcmp(awns, "4") == 0)
	shut_down();
      else
	error = 1;
    }
}

static void	check_same(t_list_rec	**list)
{
  t_list_rec	*elem1;
  t_list_rec	*elem2;
  int		i;
  int		j;
  int		a;
  int		b;

  i = 0;
  elem1 = *list;
  while (elem1 != NULL)
    {
      a = 0;
      j = 0;
      elem2 = *list;
      while (elem2 != NULL)
	{
	  if (my_strcmp(elem1->recettes, elem2->recettes) == 0 && j != i)
	    error_message("recettes : 2 * the same name of recettes");
	  j++;
	  elem2 = elem2->next;
	}
      while (elem1->ingredient[a])
	{
	  b = 0;
	  while (elem1->ingredient[b])
	    {
	      if (my_strncmp(elem1->ingredient[a], elem1->ingredient[b], go_to_pc(elem1->ingredient[a])) == 0 && a != b)
		error_message("recettes : 2 * the same ingredient in one recette");
	      b++;
	    }
	  a++;
	}
      i++;
      elem1 = elem1->next;
    }
}

static void	robby()
{
  char		*awns;
  t_file	file;
  t_all		all;

  if ((awns = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  pars_tel(&file);
  pars_vaccum(&file);
  pars_kitchen(&file);
  all.list_rec = do_list(file.recettes);
  all.entree = malloc_list(sizeof (t_list_rec));
  all.entree = NULL;
  all.dessert = malloc_list(sizeof (t_list_rec));
  all.dessert = NULL;
  all.plat = malloc_list(sizeof (t_list_rec));
  all.plat = NULL;
  check_rec(file.recettes);
  check_same(&all.list_rec);
  check_type(&all.list_rec, &all.dessert, &all.entree, &all.plat);
  menu(awns, &file, &all);
  free(awns);
  free_all(file.com);
  free_all(file.wtd);
  free_all(file.mouv_dab);
  free_all(file.frigo);
  free_all(file.recettes);
}

int		main()
{
  robby();
  return (0);
}

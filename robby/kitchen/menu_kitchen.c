/*
** menu_kitchen.c for menu_kitchen in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun 23 16:18:45 2013 clement lovergne
** Last update Sun Jun 23 16:26:16 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"../../dot_h/fonction.h"

int		again_choose()
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

int	menu2(t_list_rec **entree, t_list_rec **plat,
	      t_list_rec **dessert, char **frigo)
{
  char		**str;
  int		again;
  char		**choice;

  if ((choice = malloc(1 * sizeof(char*))) == NULL)
    error_message("malloc");
  choice[0] = NULL;
  str = choose_entree(entree, frigo);
  again = choose_this(entree, frigo, str);
  if (again != -1)
    sub_copy_choose(str[again], entree, frigo, choice);
  str = choose_entree(plat, frigo);
  again = choose_this(plat, frigo, str);
  if (again != -1)
    sub_copy_choose(str[again], plat, frigo, choice);
  str = choose_entree(dessert, frigo);
  again = choose_this(dessert, frigo, str);
  if (again != -1)
    sub_copy_choose(str[again], dessert, frigo, choice);
  display_finnish(choice, &again);
  free_all(str);
  return (again);
}

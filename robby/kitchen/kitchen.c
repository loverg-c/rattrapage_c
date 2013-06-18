/*
** kitchen.c for kitchen in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:34:14 2013 clement lovergne
** Last update Tue Jun 18 16:22:20 2013 clement lovergne
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
      my_putstr(elem->recettes);
      my_putstr("-----------");
      my_putstr(elem->type);
      my_putstr("-----------");
      my_putstr2(elem->ingredient);
      my_putchar('\n');
      elem = elem->next;
    }
}

void		go_to_kitchen(char **frigo, char **recettes)
{
  t_list_rec	*list_rec;
  int		i;
  int		j;
  char		*afterpc;

  i = 0;
  list_rec = NULL;
  while (recettes[i])
    {
      j = go_to_pc(recettes[i]);
      j++;
      afterpc = copy_afterpc(&j, recettes[i]);
      if (my_strcmp(afterpc, "entree") == 0 || my_strcmp(afterpc, "plat") == 0 ||
	  my_strcmp(afterpc, "dessert") == 0)
	my_putinlist(&list_rec, recettes, &i);
      else
	i++;
    }
  my_aff_list(&list_rec);
  sleep(5);
}

/*
** choose.c for choose in /home/loverg_c//RATTRAPAGE/rattrapage_c/robby/kitchen
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri Jun 21 18:16:01 2013 clement lovergne
** Last update Sun Jun 23 20:37:27 2013 clement lovergne
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"../../dot_h/fonction.h"

int		what_he_choose()
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

int		do_the_choose(char **str)
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
  return (a);
}

int		choose_this(t_list_rec **entree, char **frigo, char **str)
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

void		display_finnish(char **choice, int *again)
{
  if (choice[0])
    {
      my_putstr("\n\nYou choose :\n");
      my_putstr2(choice);
    }
  *again = 0;
  while (*again == 0)
    {
      my_putstr("\n\nDo you want to change it ? (yes or no)\n");
      *again = again_choose();
    }
}

void		sub_copy_choose(char *str, t_list_rec **type,
				char **frigo, char **choice)
{
  sub(str, frigo, type);
  choice = my_copy_line(choice, str);
}

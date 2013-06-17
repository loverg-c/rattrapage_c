/*
** main.c for Robby in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:25:57 2013 clement lovergne
** Last update Mon Jun 17 20:55:09 2013 clement lovergne
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

static void	menu(char *awns, t_file *file)
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
	go_to_kitchen();
      else if (my_strcmp(awns, "4") == 0)
	shut_down();
      else
	error = 1;
    }
}

static void	robby()
{
  char		*awns;
  t_file	file;

  if ((awns = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  pars_tel(&file);
  pars_vaccum(&file);
  menu(awns, &file);
  free(awns);
  free_all(file.com);
  free_all(file.wtd);
}

int		main()
{
  robby();
  return (0);
}

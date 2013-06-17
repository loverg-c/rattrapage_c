/*
** main.c for Robby in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:25:57 2013 clement lovergne
** Last update Mon Jun 17 15:57:27 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"fonction.h"

static void	display(int error, char *awns)
{
  if (system("clear") == -1)
    error_message("clear");
  if (error == 1)
    {
      my_putstr(awns);
      my_putstr(" : it's not a good choice\n");
    }
  my_putstr("\nWelcome in Robby's interface !");
  my_putstr(" You can enter 1, 2, 3 or 4 depending on your ");
  my_putstr("choice :\n\n1 - Telephone\n\n2 - Vaccum\n\n");
  my_putstr("3 - Kitchen\n\n4 - Shutdown Robby\n\n");
}

static void	shut_down()
{
  my_putstr("Good Bye !\n\n");
  exit(0);
}

static void	robby()
{
  char		*awns;
  int		error;
  int		i;
  t_file	file;

  if ((awns = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  go_to_tel(&file);
  while (42)
    {
      display(error, awns);
      all_to_zero(awns, 4096);
      error = 0;
      if ((i = read(0, awns, 4096)) == -1)
       	error_message("read");
      awns[i - 1] = '\0';
      if (my_strcmp(awns, "1") == 0)
	stay_on_phone(file.wtd, file.com);
      else if (my_strcmp(awns, "2") == 0)
	go_to_vaccum();
      else if (my_strcmp(awns, "3") == 0)
	go_to_kitchen();
      else if (my_strcmp(awns, "4") == 0)
	shut_down();
      else
	error = 1;
    }
  free(awns);
}

int		main()
{
  robby();
  return (0);
}

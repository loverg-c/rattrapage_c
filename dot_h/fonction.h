/*
** fonction.h for fonction in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:29:36 2013 clement lovergne
** Last update Mon Jun 17 21:57:58 2013 clement lovergne
*/

#ifndef		FONCTION_H_
# define	FONCTION_H_

# define	MY_SIZE	(500)

#include	"struct.h"

void		my_putchar(char);
void		my_putstr(char*);
void		my_putstr2(char**);
void		error_message(char*);
int		my_strcmp(char*, char*);
void		all_to_zero(char *, int);
void		all_to_zero2(char *, int);
void		pars_tel(t_file*);
void		go_to_vaccum(char**);
void		go_to_kitchen();
char		*get_next_line(int, int);
int		my_strlen(char*);
int		my_strlen2(char**);
void		search_error(char**);
char		*no_get_next(int*, int*);
char		*my_strcpy(char*, char*);
char		**pars_file(char **, char *);
char		**pars_commande(char**);
void		free_all(char**);
void		stay_on_phone(char**, char**);
void		pars_vaccum(t_file*);
int		count_pointcoma(char*);
void		replace_maps(char**, t_vaccum*);
void		try_to_mouv(char**, t_vaccum*, char**, int);
char		**my_copy_line(char**, char*);

#endif		/* FONCTION_H_ */

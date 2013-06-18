/*
** fonction.h for fonction in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:29:36 2013 clement lovergne
** Last update Tue Jun 18 18:08:21 2013 clement lovergne
*/

#ifndef		FONCTION_H_
# define	FONCTION_H_

# define	MY_SIZE	(500)

#include	"struct.h"

void		my_putchar(char);
void		my_putstr(char*);
void		my_putstr2(char**);
void		my_putnbr(int);
int		my_strlen(char*);
int		my_strlen2(char**);
char		*my_strcpy(char*, char*);
int		my_strcmp(char*, char*);
void		error_message(char*);
void		free_all(char**);
void		all_to_zero(char *, int);
void		all_to_zero2(char *, int);
char		*get_next_line(int, int);
char		**my_copy_line(char**, char*);
char		*no_get_next(int*, int*, char*, t_get*);
void		search_error(char**);
void		pars_tel(t_file*);
char		**pars_commande(char**);
void		stay_on_phone(char**, char**);
void		go_to_vaccum(char**);
void		pars_vaccum(t_file*);
int		count_pointcoma(char*);
void		replace_maps(char**, t_vaccum*);
int		try_to_mouv(char**, t_vaccum*, char**, int);
void		my_robby(int*, t_vaccum*);
int		search_o(char**);
void		check_pcoma(char**);
void		check_all_number(char*);
void		go_to_kitchen(char **, char**);
void		check_validrecette(char**);
void		check_validfrigo(char**);
void		pars_kitchen(t_file*);
void		my_putinlist(t_list_rec**, char**, int*);
char		*copy_afterpc(int*, char*);
int		go_to_pc(char*);

#endif		/* FONCTION_H_ */

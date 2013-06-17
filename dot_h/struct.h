/*
** struct.h for struct in /home/loverg_c//RATTRAPAGE/rattrapage_c/dot_h
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 18:49:36 2013 clement lovergne
** Last update Mon Jun 17 19:39:24 2013 clement lovergne
*/

#ifndef		STRUCT_H_
# define	STRUCT_H_

typedef struct	s_get
{
  char		*my_r;
  int		j;
}		t_get;

typedef struct	s_file
{
  char		**wtd;
  char		**com;
  char		**mouv_dab;
}		t_file;

typedef struct	s_vaccum
{
  int		robby_x;
  int		robby_y;
  int		dab_x;
  int		dab_y;
  int		old_robby_x;
  int		old_robby_y;
  int		old_dab_x;
  int		old_dab_y;
  char		old_values;
}		t_vaccum;

#endif		/* STRUCT_H_ */

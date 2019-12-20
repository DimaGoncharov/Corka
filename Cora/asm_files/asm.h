/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:33:22 by mpaincha          #+#    #+#             */
/*   Updated: 2016/12/01 18:33:25 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libftprintf/includes/ft_printf.h"
# include "op.h"
# include <fcntl.h>
# define BUFF 1024

/*
**********************  Structures  **********************
*/

typedef struct		s_final_trad
{
	char			*magic;
	char			*name;
	char			*total_oct;
	char			*comment;
	char			*instruct;

}					t_final_trad;

typedef struct		s_hexa
{
	char			*hexa;
	char			*lbl_name;
}					t_hexa;

typedef struct		s_sum_args
{
	int				type;
	int				sum;
}					t_sum_args;

typedef struct		s_tmp1
{
	char			*trad;
	char			*tmp2;
	char			*nw;
}					t_tmp1;

typedef struct		s_tmp2
{
	char			*trad;
	char			*to_trad;
}					t_tmp2;

typedef struct		s_recup
{
	int				label;
	char			*label_name;
	int				pos_oct;
	int				op_code;
	char			**args_tab;
	int				nb_arg;
	t_dbllist		*lst_hexa;
	int				nb_oct;
}					t_recup;

typedef struct		s_called
{
	char			*name;
	int				trad;
}					t_called;

typedef struct		s_data_line
{
	int				index;
	int				nb_oct;
	char			*label_declared;
	t_dbllist		*label_called;
}					t_data_line;

typedef struct		s_data
{
	char			**file;
	char			*comment;
	char			*name;
	int				nb_lines;
	t_dbllist		*label_kw;
	t_dbllist		*lst_recup;
	t_dbllist		*lst_lines;
	char			*tmp_trad;
	char			*trad;
}					t_data;

typedef struct		s_lab
{
	char			*name;
	int				oct;
}					t_lab;

typedef struct		s_var
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				toggle;
	char			**label_cleaned;
}					t_var;

typedef	void		(*t_trad)(char *, char **, t_data **, int);

/*
**********************  Initializer  *******************
*/

void				initializer(t_data **data);
void				initlab(t_lab *lab, t_data **data);
void				initrecup(t_recup **recup);
void				initdataline(t_data_line *dline, int index_line);
void				initsumary_args(t_sum_args *data);
void				inittmp1(t_tmp1 *tmp1);
void				inittmp2(t_tmp2 *tmp2);

/*
**********************  File Cleaning  *****************
*/

int					head_file(char **argv, t_data *data, int *i);
int					changer(t_data *data, int nb_lines);
int					ft_comm(int c);
int					ft_label_char(int c);
int					ft_manag_head(t_data *data);
int					ft_manag_lab(t_data *data);
int					ft_manag_name(t_data *data, int *i, int *j);
int					ft_manag_comm(t_data *data, int *i, int *j);
int					ft_out(t_data *data, char *str);

/*
**********************  Recovery  **********************
*/

int					vosstanovilka(t_data *data);
int					arg_vosstanovilka(char **args_tab, int *to_check);
int					lab_val(char *name);
int					lab_checker(char **name, t_data **data, t_data_line *line);
int					instruct_chekus(char *line, char **name, t_data **data,
					t_data_line *dline);
void				ftstrtrmtb(char **args_tab);
int					args_checkus(char **args_tab, int op_code, t_data **data);
int					args_type_difiner(char *arg);
int					type_verificator(int type, int op_code);
int					arg_nebe(char **args_tab);
int					is_label_real(char *name, t_data **data);
int					direr(char *arg);
int					regger(char *arg);
int					indyuk(char *arg);

/*
**********************  Transformation  ****************
*/

void				args_sumus(t_recup *recup, char **hexa);
void				reg_trad(char *arg, char **hexa, t_data **data,
					int op_code);
void				indus_trad(char *arg, char **hexa, t_data **data,
					int op_code);
void				dir_trad(char *arg, char **hexa, t_data **data,
					int op_code);
void				trad_args(t_recup *recup, char **hexa, t_data **data,
					int op_code);
void				trad_label(char *arg, char **hexa, t_data **data,
					int op_code);
void				trad_neg(char *arg, char **to_add);
void				reduce_hex(char **to_add, int size);
int					define_trad_fct(char *arg);
void				trad_name_instruct(int op_code, char **hexa);
void				hex_to_lower(char **hex);
void				add_zero(char **str, int width);
void				add_f(char **str, int width);
void				trad_to_str(t_data **data);
char				*lsthexa_tostr(t_dbllist *lst);
void				label_called(t_data_line *dline, char **args_tab);
int					index_label_called(char *name, t_dbllist *lst_lines);
int					index_label_declared(char *name, t_dbllist *lst_lines);
int					find_in_lst_called(char *name, t_dbllist *label_called);
void				define_index(char *name, t_data **data, int *i_called,
					int *i_declared);
void				trad_dir_label(t_data **data);
void				tmp_trad_to_str(t_data **data);
int					args_for_sum(char *arg);
void				final_trad(t_data *data, int nb_oct);
void				trad_to_ok(t_dbllist **lst_lines, char *lbl_called,
					int i_called);
void				modif_trad(int i, int j, char *trad, char **tmp_trad);
uintmax_t			ft_hextoi(unsigned char *str);
void				hexdump_reverse(char const *trad, int fd);

/*
**********************  Output  ***********************
*/

void				cora_sozdatel(t_data *data, char *file_name);

/*
**********************  No leaks  **********************
*/

void				all_data_free(t_data *data);
void				tab_char_free(char ***tab);
void				t_recup_free(t_recup *recup);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:49:43 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 14:43:24 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "../libft/includes/ft_printf.h"
# include <ncurses.h>
# define OPTIONS	"dsnvcaN"
# define REG		1
# define DIR		2
# define IND		3

/*
**********************  Structures  **********************
*/

typedef struct		s_options
{
	int				stealth;
	int				bool_dump;
	intmax_t		dump_number;
	int				bool_vm_number;
	unsigned int	vm_number;
	int				verbose;
	int				cycle;
	int				ncurse;
	int				aff;
}					t_options;
typedef struct		s_cor
{
	int				pid;
	int				nb_champ;
	unsigned int	last_live;
	int				cycles_to_die;
	unsigned int	era_lives_counter;
	int				check;
	intmax_t		cycles;
	int				era_cycles;
	unsigned int	winner_nb;
	unsigned char	*board;
	t_options		options;
	int				new_era;
	int				end;
	WINDOW			*windows[2];
	int				cycle_frequency;
	int				u_delta_sleep;
	int				process_map[4096];
	int				color_map[4096];
	int				is_paused;
	int				is_first;
	FILE			*lolol;
}					t_cor;
typedef struct		s_champ
{
	int				id;
	char			*name;
	char			*comment;
	unsigned char	*content;
	unsigned int	vm_number;
	unsigned int	size;
}					t_champ;
typedef struct		s_var
{
	char			*str;
	int				i;
	char			**argv;
	int				error;
}					t_var;
typedef struct		s_aox
{
	int				arg1;
	int				arg2;
	int				r_dest;
	int				o_code;
}					t_aox;
typedef struct		s_proc
{
	int				r[REG_NUMBER];
	int				carry;
	unsigned char	*pc;
	unsigned int	i;
	int				ctp;
	int				live;
	int				pid;
	int				last_lived;
	unsigned char	c_cmd;
	int				color;
	int				error;
}					t_proc;

/*
**********************  Display  **********************
*/

int					print_smth(int argc);
void				print_steps(unsigned char *ptr, int memsize);
void				starting(t_dbllist *champ_list);

/*
**********************  Options  **********************
*/

int					chk_options(int argc, char **argv, t_options *options,
	t_dbllist *champ_list);
void				verall(unsigned char *board, t_proc *c_proc,
	int offset);
void				versti(unsigned char *board, t_proc *c_proc,
	int p1, int p2);
void				verst(int pid, int reg_nb, int id);
void				verld(int pid, int reg_nb, int id);
void				verlive(char *cmd, int pid, int id);

/*
**********************  Checkers  **********************
*/

int					make_chmps(t_dbllist *champ_list, t_options *options,
	t_var *var);

/*
**********************  Utils  **********************
*/

int					manage_err(int ret, t_var *var);
uintmax_t			atoi_hexd(unsigned char *str);
char				*itoa_hexd(int *str, int size);
unsigned char		*get_cont(int *str, int size);
int					rev_bytes(int buf, int readv);
int					isreg(unsigned char *board, t_proc *c_proc, int *type,
	int arg_nb);
int					isdir(unsigned char *board, t_proc *c_proc, int *type,
	int arg_nb);
int					isind(unsigned char *board, t_proc *c_proc, int *type,
	int arg_nb);

/*
**********************  Memory Setter  **********************
*/

unsigned char		*memory(void);
void				init_map(t_dbllist *ch_list, t_dbllist *pr_list,
	t_cor *core);

/*
**********************  Commands **********************
*/

int					size_cmd(int *type, int label_size, int nb_param);
int					*get_type(unsigned char *board, t_proc *c_proc);
int					get_reg_name(unsigned char *board, t_proc *c_proc,
	int i[]);
int					get_arg_val(int oc_trunc, unsigned char *board,
	t_proc *c_proc, int i[]);
int					bit_cat(unsigned char *board, t_proc *c_proc, int start,
	int size);
void				next(unsigned char *board, t_proc *c_proc,
	int nb, int verbose);
void				next_pc(int counter_offset, t_proc *c_proc,
	unsigned char *board);
void				cmd_live(unsigned char *board, t_proc *c_proc, t_cor *core,
	t_dbllist *ch_list);
void				cmd_ld(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_st(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_add(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_sub(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_and(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_or(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_xor(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_zjmp(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_ldi(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_sti(unsigned char *board, t_proc *c_proc, t_cor *core);
void				sti_result(t_cor *core, t_proc *c_proc, int reg_nb,
	unsigned int add);
int					add_ind_reg(unsigned char *board, t_proc *c_proc, int v,
	int *reg_nb);
int					add_reg_reg(unsigned char *board, t_proc *c_proc, int v,
	int *reg_nb);
int					add_dir_reg(unsigned char *board, t_proc *c_proc, int v,
	int *reg_nb);
void				cmd_fork(unsigned char *board, t_proc *c_proc,
	t_dbllist *pr_list, t_cor *core);
void				cmd_lld(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_lldi(unsigned char *board, t_proc *c_proc, t_cor *core);
void				cmd_lfork(unsigned char *board, t_proc *c_proc,
	t_dbllist *pr_list, t_cor *core);
void				cmd_aff(unsigned char *board, t_proc *c_proc, t_cor *core);

/*
**********************  Game Loop **********************
*/

void				init(t_cor *core, t_options *options);
int					prog_loop(t_cor *core, t_dbllist *ch_list,
	t_dbllist *pr_list);
void				ver_loop(t_cor *core);
int					exec_dead_proc(t_dbllist **pr_list, t_cor *core);
int					is_comm(t_proc *c_proc, t_cor *core, t_dbllist *ch_list,
	t_dbllist *pr_list);
void				chk_comm(t_cor *core, t_dbllist **ch_list,
	t_dbllist **pr_list);

/*
**********************  Ncurses **********************
*/

int					setup_ncurses(t_cor *core);
int					print_map(t_cor *core, t_dbllist *process_list,
	unsigned char *board);
int					ncurs_end(t_cor *core);

#endif

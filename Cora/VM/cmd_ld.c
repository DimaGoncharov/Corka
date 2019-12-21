/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:48:08 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:48:11 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	dir_reg(unsigned char *board, t_proc *c_proc, int v)
{
	unsigned int	id;
	int				reg_nb;

	id = bit_cat(board, c_proc, 2, 4);
	reg_nb = (int)((board[(c_proc->i + 6) % MEM_SIZE] - 1));
	if (reg_nb < REG_NUMBER && reg_nb >= 0)
	{
		c_proc->r[reg_nb] = id;
		if (id == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
		if (v == 1)
			verld(c_proc->pid, c_proc->r[reg_nb], reg_nb + 1);
	}
}

static void	ind_reg(unsigned char *board, t_proc *c_proc, int v)
{
	unsigned int	id;
	int				reg_nb;

	id = bit_cat(board, c_proc, 2, 2) % IDX_MOD;
	reg_nb = (int)((board[(c_proc->i + 4) % MEM_SIZE] - 1));
	if (reg_nb < REG_NUMBER && reg_nb >= 0)
	{
		c_proc->r[reg_nb] = bit_cat(board, c_proc, ((bit_cat(board, c_proc,
			2, 2)) % MEM_SIZE), 4);
		if (c_proc->r[reg_nb] == 0)
			c_proc->carry = 1;
		else
			c_proc->carry = 0;
		if (v == 1)
			verld(c_proc->pid, c_proc->r[reg_nb], reg_nb + 1);
	}
}

void		cmd_ld(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	int				cmd_size;
	int				cmp;

	cmd_size = size_cmd(get_type(board, c_proc), 4, 2);
	if (c_proc->ctp == 5)
	{
		cmp = (board[(c_proc->i + 1) % MEM_SIZE] & 0xf0);
		if (cmp == 0x90)
			dir_reg(board, c_proc, core->options.verbose);
		else if (cmp == 0xd0)
			ind_reg(board, c_proc, core->options.verbose);
		if (core->options.verbose == 1)
			verall(board, c_proc, cmd_size);
		c_proc->ctp = 1;
		c_proc->c_cmd = 0;
		next_pc(cmd_size, c_proc, board);
	}
	else
		c_proc->ctp += 1;
}

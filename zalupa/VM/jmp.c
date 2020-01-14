/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:52:45 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:52:48 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	norm_zjmp(t_proc *c_proc, short int id)
{
	verlive("zjmp", c_proc->pid, id);
	if (c_proc->carry == 1)
		write(1, " OK\n", 4);
	else
		write(1, " FAILED\n", 8);
}

void	cmd_zjmp(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	short int	id;

	if (c_proc->ctp == 20)
	{
		id = bit_cat(board, c_proc, 1, 2);
		if (c_proc->carry == 1)
		{
			c_proc->i = (c_proc->i + (id % IDX_MOD)) % MEM_SIZE;
			c_proc->pc = &board[c_proc->i];
		}
		if (core->options.verbose == 1)
			norm_zjmp(c_proc, id);
		if (c_proc->carry == 0)
		{
			if (core->options.verbose == 1)
				verall(board, c_proc, 3);
			next_pc(3, c_proc, board);
		}
		c_proc->c_cmd = 0;
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}

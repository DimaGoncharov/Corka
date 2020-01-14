/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:49:29 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:49:33 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_aox_x(t_aox *aox, t_proc *c_proc, t_cor *core, int i[])
{
	int		o_code;

	o_code = core->board[(c_proc->i + 1) % MEM_SIZE];
	aox->arg1 = get_arg_val((o_code & 0b11000000) >> 6, core->board, c_proc, i);
	aox->arg2 = get_arg_val((o_code & 0b00110000) >> 4, core->board, c_proc, i);
	if ((o_code & 0b00001100) >> 2 == 0b01)
		aox->r_dest = get_reg_name(core->board, c_proc, i);
	else
		i[1] = -1;
	if (i[1] != -1)
	{
		c_proc->r[aox->r_dest - 1] = aox->arg1 ^ aox->arg2;
		c_proc->carry = c_proc->r[aox->r_dest - 1] == 0 ? 1 : 0;
	}
}

void		cmd_xor(unsigned char *board, t_proc *c_proc, t_cor *core)
{
	t_aox	aox;
	int		i[2];

	i[0] = 2;
	i[1] = 0;
	if (c_proc->ctp == 6)
	{
		init_aox_x(&aox, c_proc, core, i);
		if (core->options.verbose == 1)
		{
			if (i[1] == 0)
				ft_printf("P% 5d | xor %d %d r%d\n", c_proc->pid, aox.arg1,
					aox.arg2, aox.r_dest);
			verall(board, c_proc, (size_cmd(get_type(board, c_proc),
				4, 3)));
		}
		c_proc->c_cmd = 0;
		next_pc(size_cmd(get_type(board, c_proc), 4, 3), c_proc, board);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:46:47 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:46:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cmd_aff(unsigned char *b, t_proc *c_proc, t_cor *core)
{
	int		reg_nb;

	reg_nb = -1;
	if (c_proc->ctp == 2)
	{
		if ((b[(c_proc->i + 1) % MEM_SIZE] & 0xc0) == 0x40)
		{
			reg_nb = (int)((b[(c_proc->i + 2) % MEM_SIZE] - 1));
			if (reg_nb <= 15 && reg_nb >= 0)
			{
				if (core->options.aff == 0)
				{
					write(1, &c_proc->r[reg_nb], 1);
					write(1, "\n", 1);
				}
			}
		}
		if (core->options.verbose == 1)
			verall(b, c_proc, size_cmd(get_type(b, c_proc), 4, 1));
		c_proc->c_cmd = 0;
		next_pc(size_cmd(get_type(b, c_proc), 4, 1), c_proc, b);
		c_proc->ctp = 1;
	}
	else
		c_proc->ctp += 1;
}

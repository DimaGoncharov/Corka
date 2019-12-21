/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:54:23 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:54:26 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	next_pc(int counter_offset, t_proc *c_proc, unsigned char *board)
{
	c_proc->pc = &board[(c_proc->i + counter_offset) % MEM_SIZE];
	c_proc->i += counter_offset;
}

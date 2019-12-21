/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:47:19 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:47:22 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			bit_cat(unsigned char *board, t_proc *c_proc,
	int start, int size)
{
	int				result;
	unsigned int	nb;
	int				i;

	i = 0;
	nb = 0;
	result = 0;
	while (i < size)
	{
		nb = board[((c_proc->i + (start + i)) % MEM_SIZE)];
		result = result | nb;
		if (i < size - 1)
			result = result << 8;
		i++;
	}
	return (result);
}

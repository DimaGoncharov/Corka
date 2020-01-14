/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:52:14 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:52:19 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			isdir(unsigned char *board, t_proc *c_proc, int *type, int arg_nb)
{
	int		result;

	result = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
			result = bit_cat(board, c_proc, 3, 2);
		else
			result = bit_cat(board, c_proc, 4, 2);
	}
	else
		result = bit_cat(board, c_proc, 2, 2);
	return (result);
}

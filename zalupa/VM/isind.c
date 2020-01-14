/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:52:26 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:52:29 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					isind(unsigned char *board, t_proc *c_proc,
	int *type, int arg_nb)
{
	int				result;
	int				id;

	result = 0;
	if (arg_nb == 2)
	{
		if (type[0] == REG)
		{
			id = bit_cat(board, c_proc, 3, 4);
			result = bit_cat(board, c_proc, id, 4);
		}
		else
		{
			id = bit_cat(board, c_proc, 4, 4);
			result = bit_cat(board, c_proc, id, 4);
		}
	}
	else
	{
		id = bit_cat(board, c_proc, 2, 2);
		result = bit_cat(board, c_proc, id, 4);
	}
	return (result);
}

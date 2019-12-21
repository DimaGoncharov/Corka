/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_of_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:53:35 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:53:37 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_reg_name(unsigned char *board, t_proc *c_proc, int i[])
{
	int		r_dest;

	r_dest = bit_cat(board, c_proc, i[0], 1);
	i[0] += 1;
	if (r_dest <= 0 || r_dest > REG_NUMBER)
	{
		i[1] = -1;
	}
	return (r_dest);
}

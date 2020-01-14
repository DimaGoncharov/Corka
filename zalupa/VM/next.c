/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:53:59 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:54:02 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		next(unsigned char *board, t_proc *c_proc, int nb, int verbose)
{
	if (verbose == 1)
		verall(board, c_proc, nb);
	next_pc(nb, c_proc, board);
}

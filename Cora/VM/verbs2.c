/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:55:26 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:55:29 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ver_loop(t_cor *core)
{
	write(1, "It is now cycle ", 16);
	ft_putnbr(core->cycles);
	write(1, "\n", 1);
}

void		verlive(char *cmd, int pid, int id)
{
	write(1, "P", 1);
	if (pid < 10)
		write(1, " ", 1);
	if (pid < 100)
		write(1, " ", 1);
	if (pid < 1000)
		write(1, " ", 1);
	if (pid < 100000)
		write(1, " ", 1);
	if (pid >= 100000)
		write(1, " ", 1);
	ft_putnbr(pid);
	write(1, " | ", 3);
	write(1, cmd, 4);
	write(1, " ", 1);
	ft_putnbr(id);
}

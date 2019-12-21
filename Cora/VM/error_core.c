/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:50:28 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:50:31 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		print_smth(int argc)
{
	if (argc == 0)
		ft_putstr("Error in usage.\n");
	if (argc < 2)
	{
		ft_putstr("Usage: ./corewar [-d nbr_cycles] [-s] [[-n number]");
		ft_putstr(" <champion1.cor>] <...>\n");
		ft_putstr("There can be a max of only 4 champions\n");
		ft_putstr("-d N    : Dumps memory after N cycles then exits\n");
		ft_putstr("-s      : Stealth mode, does not print 'live' message\n");
		ft_putstr("-n      : Choose champion id\n");
		ft_putstr("-v      : Verbose\n");
		ft_putstr("-c      : Show cycles counter\n");
		ft_putstr("-N      : Ncurses layout, automatically disable other");
		ft_putstr("other options will automatically be disable and");
		ft_putstr(" stealth mode is automatically activated\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

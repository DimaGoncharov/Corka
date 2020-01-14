/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:50:47 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:50:52 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_steps(unsigned char *ptr, int memsize)
{
	int		i;

	i = 0;
	while (i < memsize)
	{
		if (i % 32 == 0)
		{
			if (i != 0)
				write(1, "\n", 1);
			ft_printf("0x%.4x : ", i);
		}
		ft_printf("%.2x ", ptr[i]);
		i++;
	}
	ft_putchar('\n');
}

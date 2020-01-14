/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:39:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:39:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		recover_valid_type(int op_code, int *type)
{
	int		i;

	i = 0;
	while (g_op_tab[op_code - 1].arg[i])
	{
		if (i == 0)
			(*type) = g_op_tab[op_code - 1].arg[i];
		else if (i == 1)
			(*type) = (*type) | (g_op_tab[op_code - 1].arg[i] << 4);
		else if (i == 2)
			(*type) = (*type) | (g_op_tab[op_code - 1].arg[i] << 8);
		else
			return (0);
		i++;
	}
	return (*type);
}

int				type_verificator(int type, int op_code)
{
	int		valid_type;

	recover_valid_type(op_code, &valid_type);
	if ((type & valid_type) != type)
	{
		ft_printf("One or more of arg's type is invalid\n");
		return (0);
	}
	return (1);
}

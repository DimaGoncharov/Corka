/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checkus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:39:20 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:39:24 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	print_args_tab(char **args_tab)
{
	int		i;

	i = 0;
	ft_printf("Wrong line : ");
	while (args_tab[i])
	{
		ft_printf("%s", args_tab[i]);
		i++;
	}
	ft_printf("\n");
}

static int	valid_args(char **args_tab, int op_code, int *to_check)
{
	int		type;

	type = 0;
	if (!(type = arg_vosstanovilka(args_tab, to_check)))
	{
		print_args_tab(args_tab);
		return (0);
	}
	if (!(type_verificator(type, op_code)))
		return (0);
	return (1);
}

int			arg_vosstanovilka(char **args_tab, int *to_check)
{
	int		i;
	int		type;

	i = 0;
	type = 0;
	while (args_tab[i])
	{
		type = 0;
		if ((type = args_type_difiner(args_tab[i])) == 0)
			return (0);
		if (i == 0)
			(*to_check) = type;
		else if (i == 1)
			(*to_check) = (*to_check) | (type << 4);
		else if (i == 2)
			(*to_check) = (*to_check) | (type << 8);
		else
			return (0);
		i++;
	}
	return (*to_check);
}

/*
**** Explanation (int)type :
**** sti	r1, %:live, %1
**** type :   0010  0010  0001
**** 		T_DIR T_DIR T_REG
*/

int			args_checkus(char **args_tab, int op_code, t_data **data)
{
	int		to_check;

	to_check = 0;
	if (arg_nebe(args_tab) != g_op_tab[op_code - 1].nb_param)
	{
		ft_out(*data, "Number of param for this instruction is wrong");
		return (0);
	}
	if (!(valid_args(args_tab, op_code, &to_check)))
	{
		ft_putstr(">> Non valid\n");
		return (0);
	}
	return (1);
}

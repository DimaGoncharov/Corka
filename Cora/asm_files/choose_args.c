/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:39:57 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:40:01 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				args_for_sum(char *arg)
{
	if (regger(arg))
		return (1);
	if (direr(arg))
		return (2);
	if (indyuk(arg))
		return (3);
	return (0);
}

int				args_type_difiner(char *arg)
{
	if (regger(arg))
		return (T_REG);
	if (indyuk(arg))
		return (T_IND);
	if (direr(arg))
		return (T_DIR);
	return (0);
}

int				define_trad_fct(char *arg)
{
	if (regger(arg))
		return (0);
	if (direr(arg))
		return (1);
	if (indyuk(arg))
		return (2);
	return (-1);
}

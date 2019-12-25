/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:27:34 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:27:35 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mod_octal(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax(*((unsigned short *)(&ARG->arg)), 8));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax(*((unsigned char *)(&ARG->arg)), 8));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax(*((unsigned long *)(&ARG->arg)), 8));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax(*((unsigned long long *)(&ARG->arg)), 8));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax(*((uintmax_t *)(&ARG->arg)), 8));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax(*((size_t *)(&ARG->arg)), 8));
	else
		return (ft_itoabase_uimax(*((unsigned int *)(&ARG->arg)), 8));
}

char	*mod_unsig(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax(*((unsigned short *)(&ARG->arg)), 10));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax(*((unsigned char *)(&ARG->arg)), 10));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax(*((unsigned long *)(&ARG->arg)), 10));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax(*((unsigned long long *)(&ARG->arg)), 10));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax(*((uintmax_t *)(&ARG->arg)), 10));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax(*((size_t *)(&ARG->arg)), 10));
	else
		return (ft_itoabase_uimax(*((unsigned int *)(&ARG->arg)), 10));
}

char	*mod_hexa(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_uimax(*((unsigned short *)(&ARG->arg)), 16));
	else if (SMOD.h == 2)
		return (ft_itoabase_uimax(*((unsigned char *)(&ARG->arg)), 16));
	else if (SMOD.l == 1)
		return (ft_itoabase_uimax(*((unsigned long *)(&ARG->arg)), 16));
	else if (SMOD.l == 2)
		return (ft_itoabase_uimax(*((unsigned long long *)(&ARG->arg)), 16));
	else if (SMOD.j == 1)
		return (ft_itoabase_uimax(*((uintmax_t *)(&ARG->arg)), 16));
	else if (SMOD.z == 1)
		return (ft_itoabase_uimax(*((size_t *)(&ARG->arg)), 16));
	else
		return (ft_itoabase_uimax(*((unsigned int *)(&ARG->arg)), 16));
}

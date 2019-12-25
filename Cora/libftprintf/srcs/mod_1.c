/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:27:22 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:27:23 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mod_string(t_elem *tmpa)
{
	if (SMOD.l == 1)
		return (ft_wchar_str(tmpa));
	return (ft_strdup((char *)ARG->arg));
}

char	*mod_char(t_elem *tmpa)
{
	char	*str;

	if (SMOD.l == 1)
		return (mask((wchar_t)ARG->arg));
	str = ft_strnew(1);
	str[0] = (*(char *)(&ARG->arg));
	str[1] = '\0';
	return (str);
}

char	*mod_dec(t_elem *tmpa)
{
	if (SMOD.h == 1)
		return (ft_itoabase_imax(*((signed short *)(&ARG->arg)), 10));
	else if (SMOD.h == 2)
		return (ft_itoabase_imax(*((signed char *)(&ARG->arg)), 10));
	else if (SMOD.l == 1)
		return (ft_itoabase_imax(*((long *)(&ARG->arg)), 10));
	else if (SMOD.l == 2)
		return (ft_itoabase_imax(*((long long *)(&ARG->arg)), 10));
	else if (SMOD.j == 1)
		return (ft_itoabase_imax(*((intmax_t *)(&ARG->arg)), 10));
	else if (SMOD.z == 1)
		return (ft_itoabase_imax(*((ssize_t *)(&ARG->arg)), 10));
	else
		return (ft_itoabase_imax(*((int *)(&ARG->arg)), 10));
}

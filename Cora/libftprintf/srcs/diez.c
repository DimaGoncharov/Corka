/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diez.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:24:50 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:24:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez_o(char **str)
{
	char	*tmp;

	tmp = ft_strjoinandfree("0", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexaupper(char **str)
{
	char	*tmp;

	tmp = ft_strjoinandfree("0X", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexaupper_zero(char **str, size_t len, t_elem *tmpa)
{
	char	*tmp;

	tmp = NULL;
	if (SFLAGS.width > len)
	{
		if (SFLAGS.width - len == 1)
		{
			(*str)[0] = 'X';
			tmp = ft_strjoinandfree("0", *str, 2);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
		{
			(*str)[0] = '0';
			(*str)[1] = 'X';
		}
	}
	else
	{
		tmp = ft_strjoinandfree("0X", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

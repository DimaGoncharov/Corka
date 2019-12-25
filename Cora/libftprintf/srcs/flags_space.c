/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:25:50 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:25:50 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_beforewidth(char **str)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		tmp = ft_strjoinandfree(" ", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	space_afterwidth(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		if (SFLAGS.width > len)
		{
			(*str)[0] = ' ';
			ft_strdel(&tmp);
		}
		else
		{
			tmp = ft_strjoinandfree(" ", *str, 2);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:25:20 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:25:21 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_space(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (SFLAGS.width > len)
	{
		while (!(ft_isdigit((*str)[i])))
			i++;
		if (i > 0)
		{
			(*str)[i - 1] = '-';
			return ;
		}
	}
	tmp = ft_strjoinandfree("-", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	minus_zero(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if (SFLAGS.width > len)
		(*str)[0] = '-';
	else
	{
		tmp = ft_strjoinandfree("-", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

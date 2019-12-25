/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:25:44 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:25:45 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plus_space(t_elem *tmpa, char **str, size_t len)
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
			(*str)[i - 1] = '+';
			return ;
		}
	}
	tmp = ft_strjoinandfree("+", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	plus_zero(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if (SFLAGS.width > len)
		(*str)[0] = '+';
	else
	{
		tmp = ft_strjoinandfree("+", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

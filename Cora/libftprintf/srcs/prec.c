/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:27:41 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:27:42 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_s(t_elem *tmpa, char **str)
{
	char	*tmp;

	tmp = NULL;
	if (SPREC.pt != 0 && SPREC.n < ft_strlen(*str))
	{
		tmp = ft_strnew(SPREC.n + 1);
		tmp = ft_strncpy(tmp, *str, SPREC.n);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	prec_doux(t_elem *tmpa, char **str)
{
	char		*tmp;
	size_t		i;
	size_t		nb;
	char		*add;

	i = 0;
	tmp = NULL;
	add = NULL;
	if (SPREC.n != 0 && (SPREC.n > ft_strlen(*str)))
	{
		nb = SPREC.n - ft_strlen(*str);
		add = ft_strnew(nb);
		while (i < nb)
			add[i++] = '0';
		add[i] = '\0';
		tmp = ft_strjoinandfree(add, *str, 1);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

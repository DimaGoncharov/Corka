/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:41:51 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:41:54 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_f(char **str, int width)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strlen(*str) == (size_t)width)
		return ;
	while (ft_strlen(*str) < (size_t)width)
	{
		tmp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin("f", tmp);
		ft_strdel(&tmp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:51:33 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:51:37 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*itoa_hexd(int *str, int size)
{
	int		i;
	int		j;
	char	*hex;

	i = 0;
	j = 0;
	hex = (char *)ft_memalloc((size + 1) * sizeof(int));
	while (i < size)
	{
		hex[j] = str[i] >> 24;
		hex[j + 1] = str[i] >> 16;
		hex[j + 2] = str[i] >> 8;
		hex[j + 3] = str[i];
		j += 4;
		i += 2;
	}
	return (hex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:53:25 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:53:28 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char		*memory(void)
{
	unsigned char	*plateau;
	int				i;

	i = 0;
	plateau = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (MEM_SIZE));
	return (plateau);
}

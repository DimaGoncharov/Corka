/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:47:09 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:47:12 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				rev_bytes(int buf, int readv)
{
	if (readv == (sizeof(int)))
		return (((buf >> 24) & 0xff) |
				((buf << 8) & 0xff0000) |
				((buf >> 8) & 0xff00) |
				((buf << 24) & 0xff000000));
	else if (readv == 3)
		return ((((buf << 16) & 0xff0000)) |
			((buf << 0) & 0xff00) |
			((buf >> 16) & (0xff)));
	else if (readv == 2)
		return (((buf << 8) & 0xff00) | (buf >> 8));
	else
		return (buf);
}

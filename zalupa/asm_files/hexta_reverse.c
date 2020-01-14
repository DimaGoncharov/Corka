/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexta_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:42:35 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:42:38 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	hexdump_reverse(char const *trad, int fd)
{
	uintmax_t		value;
	int				i;
	int				len;
	unsigned char	*tmp;

	value = 0;
	i = 0;
	len = ft_strlen(trad);
	while (i < len)
	{
		tmp = (unsigned char *)ft_strsub(trad, i, 2);
		value = atoi_hexd(tmp);
		write(fd, &value, 1);
		ft_strdel((char **)&tmp);
		if (i + 2 < len)
			i += 2;
		else
			break ;
	}
}

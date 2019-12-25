/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:28:57 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:28:58 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		clean_read(int fildes, char *buf, size_t nbyte)
{
	int	ret;

	ret = read(fildes, buf, nbyte);
	if (ret == -1)
	{
		ft_putstr("read() error\nexiting program\n");
		exit(EXIT_FAILURE);
	}
	buf[ret] = '\0';
	return (ret);
}

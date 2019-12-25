/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:28:51 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:28:52 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <fcntl.h>

int		clean_open(const char *path, int flag)
{
	int		fd;

	fd = open(path, flag);
	if (fd == -1)
	{
		ft_putstr("open() error\nexiting program\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

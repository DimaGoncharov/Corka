/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:40:18 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:40:22 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_s_file(char *name)
{
	if (name)
	{
		if (name[ft_strlen(name) - 1] == 's'
			&& name[ft_strlen(name) - 2] == '.')
			return (1);
	}
	return (0);
}

static char		*recup_only_name(char *file_name)
{
	int		i;
	char	*tmp;

	i = ft_strlen(file_name) - 1;
	tmp = NULL;
	while (i >= 0)
	{
		if (file_name[i] == '/')
			break ;
		i--;
	}
	tmp = ft_strsub(file_name, i + 1, ft_strlen(file_name));
	return (tmp);
}

void			cora_sozdatel(t_data *data, char *file_name)
{
	int		fd;
	char	*tmp;
	char	*name;

	fd = -1;
	tmp = NULL;
	if (!(check_s_file(file_name)))
		return ;
	tmp = recup_only_name(file_name);
	name = ft_strsub(tmp, 0, ft_strlen(tmp) - 2);
	free(tmp);
	name = ft_strjoinandfree(name, ".cor", 1);
	fd = open(name,
		O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(fd);
	open(name, O_WRONLY);
	hexdump_reverse(data->tmp_trad, fd);
	close(fd);
	ft_printf("Writing output program to %s\n", name);
	ft_strdel(&name);
}

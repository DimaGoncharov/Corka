/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manag_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:41:30 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:41:35 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	gotonextline(int *i, int *j, t_data *data, int *name_size)
{
	data->name[*name_size] = '\n';
	*i += 1;
	*j = 0;
	*name_size += 1;
}

static void	savename(t_data *data, int *name_size, int *i, int *j)
{
	data->name[*name_size] = data->file[*i][*j];
	*j += 1;
	*name_size += 1;
}

int			ft_manag_name(t_data *data, int *i, int *j)
{
	int		name_size;

	name_size = 0;
	if ((data->name = (char *)ft_memalloc(sizeof(char) * 129)) == NULL)
		ft_out(data, "data->name malloc error\n");
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		while (data->file[*i][*j] != '"' && name_size <= 128 &&
			*i <= data->nb_lines)
		{
			if (data->file[*i][*j] == '\0')
				gotonextline(i, j, data, &name_size);
			else
				savename(data, &name_size, i, j);
		}
	}
	else
		return (0);
	if (name_size > 128 || *i >= data->nb_lines)
		return (ft_out(data, ".name is too long (MAX 128 chars)\n"));
	return (1);
}

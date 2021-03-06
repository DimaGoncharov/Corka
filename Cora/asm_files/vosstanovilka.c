/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vosstanovilka.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:45:23 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:45:26 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_line(char *line, t_data **data)
{
	int				i;
	char			*name;
	t_data_line		dline;
	static int		index_line = 0;

	i = 0;
	name = NULL;
	initdataline(&dline, index_line);
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_strsub(line, 0, i);
	if (name[ft_strlen(name) - 1] == ':')
	{
		if (lab_checker(&name, data, &dline) == 0)
			return (0);
	}
	else
	{
		if (instruct_chekus(line, &name, data, &dline) == 0)
			return (0);
	}
	ft_strdel(&name);
	ft_lstdbladd_head((*data)->lst_lines, &dline, sizeof(t_data_line));
	index_line += 1;
	return (1);
}

int				vosstanovilka(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_lines)
	{
		if (data->file[i] == NULL)
			return (1);
		if (!(check_line(data->file[i], &data)))
			return (0);
		i++;
	}
	return (1);
}

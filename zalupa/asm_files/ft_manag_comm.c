/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manag_comm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:41:01 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:41:04 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		gotonextline(int *i, int *j, t_data *data, int *comment_size)
{
	data->comment[*comment_size] = '\n';
	*i += 1;
	*j = 0;
	*comment_size += 1;
}

static void		savecomment(t_data *data, int *comment_size, int *i, int *j)
{
	data->comment[*comment_size] = data->file[*i][*j];
	*j += 1;
	*comment_size += 1;
}

static void		nocomment(t_data *data, int *i, int *j, int comment_size)
{
	if (data->file[*i][*j] == '"')
		data->comment[comment_size] = '\0';
}

int				ft_manag_comm(t_data *data, int *i, int *j)
{
	int		comment_size;

	comment_size = 0;
	if ((data->comment = (char *)ft_memalloc(sizeof(char) * 2049)) == NULL)
		ft_out(data, "data->comment malloc error\n");
	while (data->file[*i][*j] == ' ' || data->file[*i][*j] == '\t')
		*j += 1;
	if (data->file[*i][*j] == '"')
	{
		*j += 1;
		nocomment(data, i, j, comment_size);
		while ((data->file[*i][*j] != '"' && comment_size <= 2048 &&
			*i <= data->nb_lines))
		{
			if (data->file[*i][*j] == '\0')
				gotonextline(i, j, data, &comment_size);
			else
				savecomment(data, &comment_size, i, j);
		}
	}
	else
		return (0);
	if (comment_size > 2048 || *i >= data->nb_lines)
		return (ft_out(data, "comment is too long (2048 chars)\n"));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:42:12 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:42:15 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		head_file(char **argv, t_data *data, int *i)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_out(data, "Open error\n");
	if (data->file != NULL)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			data->file[*i] = line;
			*i += 1;
			if (*i % 1024 == 0)
				(((data->file = realloc(data->file, 1024)) == NULL) ?
					ft_out(data, "Realloc error\n") : 0);
		}
		((ret == -1) ? ft_out(data, "Read error\n") : 0);
	}
	else
		return (0);
	return (1);
}

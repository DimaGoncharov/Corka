/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:43:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:07:53 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 0;
	initializer(&data);
	if (argc != 1)
	{
		head_file(argv, data, &i);
		changer(data, i);
	}
	else
		ft_out(data, "Please provide a .s file");
	if (!(vosstanovilka(data)))
	{
		all_data_free(data);
		return(0);
	}
	tmp_trad_to_str(&data);
	trad_dir_label(&data);
	final_trad(data, ft_strlen(data->tmp_trad) / 2);
	cora_sozdatel(data, argv[1]);
	all_data_free(data);
	return(0);
}

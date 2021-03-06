/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:49:57 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:50:01 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		filetotab(int **stock, int *file_size, t_var *var)
{
	int	fd;
	int	buf;
	int	readv;

	if ((fd = open(var->argv[var->i], O_RDONLY)) == -1)
		return (0);
	while ((readv = read(fd, &buf, sizeof(int))) != 0)
	{
		if (readv == -1)
			return (-1);
		else if ((*file_size + readv * 2) > COR_MAX_VALUE)
			return (-2);
		else
		{
			buf = rev_bytes(buf, readv);
			ft_memcpy(&(*stock)[*file_size / sizeof(int)], &buf, sizeof(int));
			buf = 0;
			*file_size += readv * 2;
		}
	}
	return (((*file_size) <= COR_MIN_VALUE) ? -3 : 1);
}

static int		champion_validity_checker(t_var *var, t_champ *champ)
{
	int					file_size;
	int					*stock;
	int					ret;

	file_size = 0;
	stock = (int *)ft_memalloc((COR_MAX_VALUE / 2) * sizeof(int));
	if ((ret = filetotab(&stock, &file_size, var)) != 1)
		return (manage_err(ret, var));
	if (COREWAR_EXEC_MAGIC != stock[0])
		return (manage_err(-4, var));
	champ->name = itoa_hexd(&stock[EXEC_MAGIC_LENGTH / 2], PROG_NAME_LENGTH);
	if ((champ->size = stock[PROG_NAME_LENGTH / 2 + EXEC_MAGIC_LENGTH]) !=
		(unsigned int)((file_size - COR_MIN_VALUE) / 2))
		return (manage_err(-5, var));
	champ->comment = itoa_hexd(&stock[(EXEC_MAGIC_LENGTH +
		PROG_NAME_LENGTH) / 2 + PAD], COMMENT_LENGTH);
	champ->content = get_cont(&stock[(COR_MIN_VALUE / 4)], champ->size * 2);
	free(stock);
	return (1);
}

static int		set_champion(t_var *var, t_options *opt, t_champ *champ)
{
	static int			id = 1;
	static unsigned int	vm_number = -1;

	champ->id = id;
	id++;
	if (opt->bool_vm_number == 1)
	{
		champ->vm_number = opt->vm_number;
		opt->vm_number = 0;
	}
	else
	{
		champ->vm_number = vm_number;
		vm_number--;
	}
	return (champion_validity_checker(var, champ));
}

int				make_chmps(t_dbllist *champ_list, t_options *options,
	t_var *var)
{
	t_champ				champ;

	ft_bzero(&champ, sizeof(t_champ));
	if (set_champion(var, options, &champ) == 0)
		return (0);
	ft_lstdbladd_tail(champ_list, &champ, sizeof(t_champ));
	return (1);
}

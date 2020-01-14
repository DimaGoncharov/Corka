/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:53:16 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:53:19 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_winner(t_cor *core, t_dbllist *ch_list)
{
	t_elem			*tmp;

	tmp = ch_list->head;
	while (tmp != NULL)
	{
		if (core->winner_nb == ((t_champ *)(tmp->content))->vm_number)
		{
			ft_printf("Do you know that player %d(%s) won?!!!\n",
				((t_champ *)(tmp->content))->id,
				((t_champ *)(tmp->content))->name);
		}
		tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_cor			core;
	t_options		options;
	t_dbllist		*champ_list;
	t_dbllist		*process_list;

	ft_bzero(&core, sizeof(t_cor));
	ft_bzero(&options, sizeof(t_options));
	champ_list = ft_lstdblnew();
	process_list = ft_lstdblnew();
	if (!print_smth(argc))
		exit(0);
	if (chk_options(argc, argv, &options, champ_list) == 0)
		exit(0);
	init(&core, &options);
	starting(champ_list);
	init_map(champ_list, process_list, &core);
	while (prog_loop(&core, champ_list, process_list) != 1)
		;
	if (options.ncurse == 1)
		ncurs_end(&core);
	check_winner(&core, champ_list);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_proc_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:50:09 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 14:40:31 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_dead_proc(t_dbllist **pr_list, t_cor *core)
{
	t_elem		*tmp;
	t_elem		*tmp_next;

	tmp = (*pr_list)->head;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		if (((t_proc *)(tmp->content))->live == 0 || core->cycles_to_die <= 0)
		{
			if (core->options.verbose == 1)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					((t_proc *)(tmp->content))->pid,
					((t_proc *)(tmp->content))->last_lived,
					core->cycles_to_die);
			ft_lstdbldelone(pr_list, tmp);
		}
		else
			((t_proc *)(tmp->content))->live = 0;
		tmp = tmp_next;
	}
	if ((*pr_list)->length == 0)
		core->winner_nb = core->last_live;
	return ((*pr_list)->length);
}

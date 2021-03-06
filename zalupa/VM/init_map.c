/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:51:54 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:51:57 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	content_to_board(t_elem *champ, t_cor *core,
	t_dbllist *ch_list, t_proc *proc)
{
	int					i;
	unsigned int		j;
	unsigned char		*str;

	i = (((MEM_SIZE) / ch_list->length) *
		((((t_champ *)(champ->content))->id) - 1));
	proc->i = i;
	j = 0;
	str = (unsigned char *)ft_memalloc(3);
	proc->pc = &(core->board[i]);
	proc->live = 0;
	proc->ctp = 0;
	while (j < (((t_champ *)(champ->content))->size) * 2)
	{
		str[0] = (((t_champ *)(champ->content))->content[j]);
		str[1] = (((t_champ *)(champ->content))->content[j + 1]);
		core->board[i] = (unsigned char)atoi_hexd(str);
		core->color_map[i] = ((t_champ *)(champ->content))->id;
		j += 2;
		i += 1;
	}
	proc->r[0] = (((t_champ *)(champ->content))->vm_number);
	proc->pid = core->pid;
	proc->color = ((t_champ *)(champ->content))->id;
	free(str);
}

void		init_map(t_dbllist *ch_list, t_dbllist *pr_list, t_cor *core)
{
	t_elem	*champ;
	t_proc	proc;

	champ = ch_list->head;
	bzero(&proc, sizeof(t_proc));
	while (champ != NULL)
	{
		core->pid += 1;
		content_to_board(champ, core, ch_list, &proc);
		ft_lstdbladd_head(pr_list, (t_proc *)&proc, sizeof(t_proc));
		core->last_live = ((t_champ *)champ->content)->vm_number;
		champ = champ->next;
	}
}

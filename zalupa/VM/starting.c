/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:54:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:54:51 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	starting(t_dbllist *champ_list)
{
	t_elem	*tmp;

	tmp = champ_list->head;
	ft_printf("Introducing contestants...\n");
	while (tmp != NULL)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			(((t_champ *)(tmp->content))->id),
			(((t_champ *)(tmp->content))->size),
			(((t_champ *)(tmp->content))->name),
			(((t_champ *)(tmp->content))->comment));
		tmp = tmp->next;
	}
}

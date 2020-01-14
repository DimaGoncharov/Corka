/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:39:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 14:39:46 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdbldel(t_dbllist **list)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*list)->head;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
	free(*list);
	*list = NULL;
}

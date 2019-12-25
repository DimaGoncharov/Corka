/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlsthead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:33:36 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:33:36 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putlsthead(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlsttail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:33:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:33:42 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putlsttail(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = list->tail;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->prev;
	}
}

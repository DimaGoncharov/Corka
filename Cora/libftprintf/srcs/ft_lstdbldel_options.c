/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:26:22 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:26:25 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdbldel_str(t_dbllist *list)
{
	t_elem	*tmps;

	tmps = list->head;
	while (tmps != NULL)
	{
		ft_strdel(&(SSTR->str));
		free(tmps->content);
		tmps->content = NULL;
		free(tmps);
		tmps = tmps->next;
	}
	list->tail = NULL;
	list->head = NULL;
}

void	ft_lstdbldel_arg(t_dbllist *list)
{
	t_elem	*tmpa;

	tmpa = list->head;
	while (tmpa != NULL)
	{
		ft_strdel(&(ARG->spec));
		free(tmpa->content);
		tmpa->content = NULL;
		free(tmpa);
		tmpa = tmpa->next;
	}
	list->tail = NULL;
	list->head = NULL;
}

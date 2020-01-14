/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_off.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:43:32 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:43:36 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lst_hexa(t_dbllist **lst_hexa)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*lst_hexa)->head;
	while (tmp != NULL)
	{
		if (((t_hexa *)((tmp)->content))->hexa)
			ft_strdel(&(((t_hexa *)((tmp)->content))->hexa));
		if (((t_hexa *)((tmp)->content))->lbl_name)
			ft_strdel(&(((t_hexa *)((tmp)->content))->lbl_name));
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*lst_hexa)->tail = NULL;
	(*lst_hexa)->head = NULL;
	free(*lst_hexa);
	*lst_hexa = NULL;
}

void	t_recup_free(t_recup *recup)
{
	if (recup->label_name)
		ft_strdel(&(recup->label_name));
	if (recup->args_tab)
	{
		ft_free2dtab((void **)recup->args_tab, arg_nebe(recup->args_tab));
	}
	if (recup->lst_hexa)
	{
		free_lst_hexa(&(recup->lst_hexa));
		free((recup->lst_hexa));
		recup->lst_hexa = NULL;
	}
}

void	free_tab_char(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(tab[i]);
		i++;
	}
}

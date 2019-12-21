/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:43:02 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:43:05 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				index_label_declared(char *name, t_dbllist *lst_lines)
{
	t_elem	*tmp;

	tmp = lst_lines->tail;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->label_declared)
		{
			if (!(ft_strcmp(name,
				((t_data_line *)((tmp)->content))->label_declared)))
				return (((t_data_line *)((tmp)->content))->index);
		}
		tmp = tmp->prev;
	}
	return (-1);
}

int				index_label_called(char *name, t_dbllist *lst_lines)
{
	t_elem	*tmp;

	tmp = lst_lines->tail;
	while (tmp != NULL)
	{
		if (((t_data_line *)((tmp)->content))->label_called)
		{
			if (find_in_lst_called(name,
				((t_data_line *)((tmp)->content))->label_called))
				return (((t_data_line *)((tmp)->content))->index);
		}
		tmp = tmp->prev;
	}
	return (-1);
}

static	int		is_dir_with_label(char *arg)
{
	int		i;
	char	*label;
	int		ret;

	i = 0;
	label = NULL;
	ret = 0;
	if (arg[i] != '%')
		return (0);
	if (arg[++i] == ':')
	{
		label = ft_strsub(arg, i + 1, ft_strlen(arg));
		if (lab_val(label))
			ret = 1;
		ft_strdel(&label);
		return (1);
	}
	return (ret);
}

void			label_called(t_data_line *dline, char **args_tab)
{
	int				i;
	int				j;
	t_called		caller;

	i = 0;
	j = 0;
	ft_bzero(&caller, sizeof(t_called));
	while (args_tab[i])
	{
		if (is_dir_with_label(args_tab[i]))
		{
			caller.name = ft_strsub(args_tab[i], 2, ft_strlen(args_tab[i]));
			caller.trad = 0;
			ft_lstdbladd_head(dline->label_called, &caller, sizeof(t_called));
			j++;
		}
		i++;
	}
}

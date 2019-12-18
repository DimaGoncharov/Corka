/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		save_label(char *name, t_data **data)
{
	t_lab	lab;

	initlab(&lab, data);
	lab.name = ft_strdup(name);
	if (is_label_real(name, data))
		ft_lstdbladd_head((*data)->label_kw, &lab, sizeof(t_lab));
	return (1);
}

int				is_label_real(char *name, t_data **data)
{
	t_elem	*tmp;

	tmp = ((*data)->label_kw)->tail;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_lab *)((tmp)->content))->name, name) == 0)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int				lab_val(char *name)
{
	int		i;

	i = 0;
	while (name[i] != '\0')
	{
		if (!(ft_strchr(LABEL_CHARS, name[i])))
		{
			ft_putstr("LABEL_CHARS error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int				lab_checker(char **name, t_data **data, t_data_line *dline)
{
	t_recup		recup;
	char		*tmp;

	ft_bzero(&recup, sizeof(t_recup));
	recup.label = 1;
	tmp = *name;
	*name = ft_strsub(*name, 0, ft_strlen(*name) - 1);
	free(tmp);
	if (!(lab_val(*name)))
	{
		ft_strdel(name);
		return (0);
	}
	if (!(save_label(*name, data)))
		return (1);
	recup.label_name = ft_strdup(*name);
	dline->label_declared = ft_strdup(*name);
	dline->nb_oct = 0;
	ft_lstdbladd_head((*data)->lst_recup, &recup, sizeof(t_recup));
	return (1);
}

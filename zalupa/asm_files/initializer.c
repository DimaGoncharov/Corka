/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:42:43 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:42:47 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		initializer(t_data **data)
{
	*data = (t_data *)ft_memalloc(sizeof(t_data));
	if (*data)
	{
		((((*data)->file = (char **)ft_memalloc(sizeof(char *) * BUFF)) == NULL)
		? ft_out(*data, "File malloc error\n") : 0);
		(*data)->comment = NULL;
		(*data)->name = NULL;
		((((*data)->label_kw = ft_lstdblnew()) == NULL) ?
			ft_out(*data, "label_kw malloc error") : 0);
		((((*data)->lst_recup = ft_lstdblnew()) == NULL) ?
			ft_out(*data, "lst_data malloc error") : 0);
		((((*data)->lst_lines = ft_lstdblnew()) == NULL) ?
			ft_out(*data, "lst_lines malloc error") : 0);
	}
	else
		ft_out(*data, "Couldn't malloc data");
}

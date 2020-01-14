/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:40:20 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 14:40:23 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_free2dtab(void **tab, int tab_size)
{
	int		i;

	i = 0;
	while (i < tab_size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

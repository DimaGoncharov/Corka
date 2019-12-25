/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:34:21 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:34:22 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_realloc(char **tab)
{
	char		**realloced;
	int			i;
	static int	j = 0;

	i = 0;
	j++;
	realloced = (char **)ft_memalloc(sizeof(char *) * ((1 + j) * 1024));
	while (i <= (j * 1024 - 1))
	{
		realloced[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (realloced);
}

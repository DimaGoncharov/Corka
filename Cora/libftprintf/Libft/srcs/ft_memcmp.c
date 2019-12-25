/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:32:29 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:32:30 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;

	i = 0;
	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((n - 1) > i)
	{
		if (s1_bis[i] != s2_bis[i])
			return (s1_bis[i] - s2_bis[i]);
		i++;
	}
	return (s1_bis[i] - s2_bis[i]);
}

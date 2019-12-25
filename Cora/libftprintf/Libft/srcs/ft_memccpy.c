/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:32:11 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:32:12 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	c2 = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n > i && src1[i] != c2)
	{
		dst1[i] = src1[i];
		i++;
	}
	if (n == i)
		return (NULL);
	if (src1[i] == c2)
	{
		dst1[i] = src1[i];
		i++;
	}
	return ((void *)&dst1[i]);
}

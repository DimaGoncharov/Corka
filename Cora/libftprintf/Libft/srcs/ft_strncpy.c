/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:36:33 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:36:34 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (n > i && src[i] != '\0')
	{
		dst[i] = (char)src[i];
		i++;
	}
	if (n > i)
	{
		while (n > i)
			dst[i++] = '\0';
	}
	if (n < i)
		dst[i] = '\0';
	return (dst);
}

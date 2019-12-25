/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:32:52 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:32:52 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*src_tmp;

	src_tmp = (void *)malloc(sizeof(void) * len);
	if (src_tmp == NULL)
		return (NULL);
	ft_memcpy(src_tmp, src, len);
	ft_memcpy(dst, src_tmp, len);
	free(src_tmp);
	return (dst);
}

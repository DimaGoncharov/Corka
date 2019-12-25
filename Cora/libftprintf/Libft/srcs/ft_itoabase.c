/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:30:44 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:30:44 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_itoabase(int n, size_t base)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	len = ft_intlenbase(n, base);
	nb = (unsigned int)n;
	str = ft_strnew(len + 1);
	if (base == 10 && n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (nb != 0)
	{
		if (base > 10 && nb % base >= 10)
			str[--len] = (nb % base) + 55;
		else
			str[--len] = (nb % base) + 48;
		nb = nb / base;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_uimax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:26:09 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:26:10 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_intlenbase_uimax(uintmax_t n, size_t base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_itoabase_uimax(uintmax_t n, size_t base)
{
	char			*str;
	size_t			len;

	len = ft_intlenbase_uimax(n, base);
	str = ft_strnew(len + 1);
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		if (base > 10 && n % base >= 10)
			str[--len] = (n % base) + 55;
		else
			str[--len] = (n % base) + 48;
		n = n / base;
	}
	return (str);
}

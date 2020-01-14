/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_imax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:40:11 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 14:40:13 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_intlenbase_imax(intmax_t n, size_t base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_itoabase_imax(intmax_t n, size_t base)
{
	char			*str;
	size_t			len;

	len = ft_intlenbase_imax(n, base);
	str = ft_strnew(len + 1);
	if (base == 10 && n < 0)
	{
		n = -n;
		str[0] = '-';
	}
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

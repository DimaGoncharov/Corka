/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:36:59 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:36:59 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	int		ilen;
	char	c;

	i = 0;
	len = ft_strlen(str);
	ilen = len - 1;
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[ilen];
		str[ilen] = c;
		i++;
		ilen--;
	}
	return (str);
}

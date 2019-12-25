/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:29:14 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:29:15 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char const *s, char c)
{
	int		i;
	int		count;
	int		ok;

	i = 0;
	count = 0;
	ok = 1;
	while (s[i])
	{
		if (s[i] != c && ok)
		{
			count++;
			ok = 0;
		}
		else if (s[i] == c)
			ok = 1;
		i++;
	}
	return (count);
}

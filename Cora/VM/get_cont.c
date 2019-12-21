/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:51:08 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:51:11 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned char	*addzero(unsigned char *str, int len)
{
	int				size;

	size = len - ft_strlen((char *)str);
	while (size > 0)
	{
		str = (unsigned char *)ft_strjoinandfree("0", (char *)str, 2);
		size--;
	}
	return (str);
}

static void				tolower(unsigned char *content, int tmp)
{
	int				i;

	i = 0;
	while (i < tmp)
	{
		content[i] = ft_tolower(content[i]);
		i++;
	}
}

unsigned char			*get_cont(int *str, int size)
{
	unsigned char	*content;
	unsigned char	*nb;
	int				i;
	int				len;
	int				tmp;

	content = (unsigned char *)ft_memalloc(1);
	i = 0;
	tmp = size;
	while (size > 0)
	{
		if (size >= 8)
			len = 8;
		else
			len = size;
		nb = addzero((unsigned char *)ft_itoabase_uimax((unsigned int)str[i],
			16), len);
		content = (unsigned char *)ft_strjoinandfree((char *)content,
			(char *)nb, 3);
		i += 2;
		size -= 8;
	}
	tolower(content, tmp);
	return (content);
}

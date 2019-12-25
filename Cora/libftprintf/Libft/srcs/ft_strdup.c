/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:35:06 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:35:07 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup;

	if (s1 != NULL)
	{
		strdup = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
		if (strdup == NULL)
			return (NULL);
		return (ft_strcpy(strdup, s1));
	}
	return (NULL);
}

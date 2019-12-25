/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:36:49 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:36:49 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j] && i + j < n)
				j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
			i++;
			j = 0;
		}
		return (NULL);
	}
}

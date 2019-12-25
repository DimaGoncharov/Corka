/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:36:22 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:36:22 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	lg_s1;
	size_t	i;

	i = 0;
	lg_s1 = ft_strlen(s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (n > i && s1)
	{
		s1[lg_s1 + i] = s2[i];
		i++;
	}
	s1[lg_s1 + i] = '\0';
	return (s1);
}

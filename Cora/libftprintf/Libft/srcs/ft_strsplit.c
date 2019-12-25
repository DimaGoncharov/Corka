/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:37:04 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:37:05 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_strlen_words(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char		*ft_putword(char const *s, size_t *i, char c)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * ft_strlen_words(s + *i, c) + 1);
	if (word == NULL)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		word[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str[j] = ft_putword(s, &i, c);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:30:27 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/25 15:30:28 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

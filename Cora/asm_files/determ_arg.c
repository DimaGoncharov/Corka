/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determ_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:40:32 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:40:36 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			indyuk(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		else if (!(ft_isdigit(arg[i])))
			return (0);
		else
			i++;
	}
	return (T_IND);
}

int			is_dir_label(char *arg, char **label)
{
	int		ret;

	ret = 0;
	*label = ft_strsub(arg, 2, ft_strlen(arg));
	if (lab_val(*label))
		ret = 2;
	ft_strdel(label);
	return (ret);
}

int			direr(char *arg)
{
	int		i;
	char	*label;

	i = 0;
	label = NULL;
	if (arg[i] != '%')
		return (0);
	if (arg[++i] == ':')
		return (is_dir_label(arg, &label) == 2 ? 2 : 0);
	while (arg[i])
	{
		if (i == 1 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		else if (!(ft_isdigit(arg[i])))
			return (0);
		else
			i++;
	}
	return (T_DIR);
}

int			regger(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] != 'r')
		return (0);
	i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	if (i > 3)
		return (0);
	return (T_REG);
}

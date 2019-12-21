/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:50:19 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:50:22 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	invalid_file2(int error, t_var *var)
{
	if (error == 3)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" has an invalid header.\n", 2);
	}
	else if (error == 4)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" is not the size specified in header.\n", 2);
	}
}

static void	invalid_file(int error, t_var *var)
{
	if (error == 1)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" must be at most ", 2);
		ft_putnbr_fd(COR_MAX_VALUE, 2);
		ft_putstr_fd(" bytes to be a valid champion.\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd("must be at least ", 2);
		ft_putnbr_fd(COR_MIN_VALUE + 1, 2);
		ft_putstr_fd(" bytes to be a valid champion.\n", 2);
	}
	invalid_file2(error, var);
}

int			manage_err(int ret, t_var *var)
{
	ft_putstr_fd("Error: ", 2);
	if (ret == 0)
		ft_putstr_fd("Open error.\n", 2);
	else if (ret == -1)
		ft_putstr_fd("Read error.\n", 2);
	else if (ret == -2)
		invalid_file(1, var);
	else if (ret == -3)
		invalid_file(2, var);
	else if (ret == -4)
		invalid_file(3, var);
	else if (ret == -5)
		invalid_file(4, var);
	return (0);
}

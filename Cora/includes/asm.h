/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:59:26 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/12/03 21:17:10 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "libft.h"

void	assemble(char *filename);

void	disassemble(char *filename);

/*
** Filename
*/

t_bool	is_filename(const char *filename, const char *ext);

char	*replace_extension(char *filename, char *old, char *new);

/*
** Print
*/

void	print_help(void);

/*
** Utils
*/

void	terminate(char *s);

#endif

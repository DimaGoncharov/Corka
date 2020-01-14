/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_lp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:54:31 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/12/21 17:54:34 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			init(t_cor *core, t_options *options)
{
	int				i;

	i = -1;
	core->options = *options;
	core->board = memory();
	core->cycles_to_die = CYCLE_TO_DIE;
	core->era_cycles = 0;
	core->cycles = 0;
	core->end = -1;
	while (++i < MEM_SIZE)
		core->color_map[i] = 0;
	if (options->ncurse == 1)
	{
		core->options.stealth = 1;
		core->options.aff = 1;
		core->options.verbose = 0;
		core->options.cycle = 0;
		core->options.bool_dump = 0;
		core->options.bool_vm_number = 0;
		setup_ncurses(core);
	}
}

static void		set_new_era(t_cor *core, t_dbllist *pr_list)
{
	t_elem			*tmp;

	tmp = pr_list->head;
	core->cycles_to_die -= CYCLE_DELTA;
	core->era_cycles = 0;
	core->era_lives_counter = 0;
	core->check = 0;
	while (tmp != NULL)
	{
		((t_proc *)(tmp->content))->live = 0;
		tmp = tmp->next;
	}
	if (core->options.cycle == 1)
	{
		write(1, "Cycle to die is now ", 20);
		ft_putnbr(core->cycles_to_die);
		write(1, "\n", 1);
	}
}

static void		end_era(t_dbllist **process_list, t_cor *core)
{
	core->end = exec_dead_proc(process_list, core);
	if (core->era_lives_counter >= NBR_LIVE || (core->check + 1) == MAX_CHECKS)
		set_new_era(core, *process_list);
	else
		core->check += 1;
	core->era_lives_counter = 0;
}

static void		last_lived_add(t_dbllist **pr_list)
{
	t_elem	*tmp;

	if ((*pr_list))
	{
		tmp = (*pr_list)->head;
		while (tmp != NULL)
		{
			((t_proc *)(tmp->content))->last_lived += 1;
			tmp = tmp->next;
		}
	}
}

int				prog_loop(t_cor *core, t_dbllist *ch_list, t_dbllist *pr_list)
{
	if (core->options.cycle == 1 && core->cycles != 0)
		ver_loop(core);
	chk_comm(core, &ch_list, &pr_list);
	if (core->options.ncurse == 1)
		print_map(core, pr_list, core->board);
	if (core->cycles_to_die <= 0 ||
		(((core->era_cycles + 1) % core->cycles_to_die) == 1 &&
			(core->cycles != 0)))
		end_era(&pr_list, core);
	if (core->options.bool_dump == 1 &&
		core->cycles == core->options.dump_number)
	{
		print_steps(core->board, MEM_SIZE);
		return (1);
	}
	last_lived_add(&pr_list);
	core->cycles += 1;
	core->era_cycles += 1;
	if (core->end == 0)
		return (1);
	return (0);
}

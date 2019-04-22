/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:12:51 by fkuhn             #+#    #+#             */
/*   Updated: 2019/04/18 20:03:14 by ttreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "libft.h"

int		main(int argc, char *argv[])
{
	t_vm		*vm;
	t_op		op_tab[17];

	vm = vm_new();
	args_read(argc, argv, vm);
	if (!vm->champion_count)
	{
		ft_printf("Count of champions must be between 2 and %d.\n", MAX_PLAYERS);
		exit(1);
	}
	vm->winner = vm->champion[0];
	read_all_champs(vm->champion);
	vm_spread_champs(vm, vm->champion);
	introduce_players(vm->champion);
	init_optab(op_tab);
	while (!vm->end_game)
	{
		do_cyrcle(vm, op_tab);
		if (!vm->cycles_to_dump)
			vm_dump_memory(vm->memory);
	}
	ft_printf("Winner is %s!\n", vm->winner->name);
	free(vm);
	return (0);
}
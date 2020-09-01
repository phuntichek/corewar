/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:08:34 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/14 18:08:38 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		set_param_4(t_corewar **corewar)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 256)
			((*corewar)->operations.arg_valid)[i][j++] = false;
		i++;
	}
	((*corewar)->operations.arg_valid)[0][128] = true;
	((*corewar)->operations.arg_valid)[1][144] = true;
	((*corewar)->operations.arg_valid)[1][208] = true;
	((*corewar)->operations.arg_valid)[2][80] = true;
	((*corewar)->operations.arg_valid)[2][112] = true;
	((*corewar)->operations.arg_valid)[3][84] = true;
	((*corewar)->operations.arg_valid)[4][84] = true;
	((*corewar)->operations.arg_valid)[8][128] = true;
	((*corewar)->operations.arg_valid)[11][128] = true;
	((*corewar)->operations.arg_valid)[12][144] = true;
	((*corewar)->operations.arg_valid)[12][208] = true;
	((*corewar)->operations.arg_valid)[14][128] = true;
	((*corewar)->operations.arg_valid)[15][64] = true;
	setter(corewar);
}

static void		set_param_3(t_corewar **corewar)
{
	((*corewar)->operations.arg_type)[8] = false;
	((*corewar)->operations.arg_type)[9] = true;
	((*corewar)->operations.arg_type)[10] = true;
	((*corewar)->operations.arg_type)[11] = false;
	((*corewar)->operations.arg_type)[12] = true;
	((*corewar)->operations.arg_type)[13] = true;
	((*corewar)->operations.arg_type)[14] = false;
	((*corewar)->operations.arg_type)[15] = true;
	((*corewar)->operations.arg_num)[0] = 1;
	((*corewar)->operations.arg_num)[1] = 2;
	((*corewar)->operations.arg_num)[2] = 2;
	((*corewar)->operations.arg_num)[3] = 3;
	((*corewar)->operations.arg_num)[4] = 3;
	((*corewar)->operations.arg_num)[5] = 3;
	((*corewar)->operations.arg_num)[6] = 3;
	((*corewar)->operations.arg_num)[7] = 3;
	((*corewar)->operations.arg_num)[8] = 1;
	((*corewar)->operations.arg_num)[9] = 3;
	((*corewar)->operations.arg_num)[10] = 3;
	((*corewar)->operations.arg_num)[11] = 1;
	((*corewar)->operations.arg_num)[12] = 2;
	((*corewar)->operations.arg_num)[13] = 3;
	((*corewar)->operations.arg_num)[14] = 1;
	((*corewar)->operations.arg_num)[15] = 1;
	set_param_4(corewar);
}

static void		set_param_2(t_corewar **corewar)
{
	((*corewar)->operations.carry)[0] = false;
	((*corewar)->operations.carry)[1] = true;
	((*corewar)->operations.carry)[2] = false;
	((*corewar)->operations.carry)[3] = true;
	((*corewar)->operations.carry)[4] = true;
	((*corewar)->operations.carry)[5] = true;
	((*corewar)->operations.carry)[6] = true;
	((*corewar)->operations.carry)[7] = true;
	((*corewar)->operations.carry)[8] = false;
	((*corewar)->operations.carry)[9] = false;
	((*corewar)->operations.carry)[10] = false;
	((*corewar)->operations.carry)[11] = false;
	((*corewar)->operations.carry)[12] = true;
	((*corewar)->operations.carry)[13] = true;
	((*corewar)->operations.carry)[14] = false;
	((*corewar)->operations.carry)[15] = false;
	((*corewar)->operations.arg_type)[0] = false;
	((*corewar)->operations.arg_type)[1] = true;
	((*corewar)->operations.arg_type)[2] = true;
	((*corewar)->operations.arg_type)[3] = true;
	((*corewar)->operations.arg_type)[4] = true;
	((*corewar)->operations.arg_type)[5] = true;
	((*corewar)->operations.arg_type)[6] = true;
	((*corewar)->operations.arg_type)[7] = true;
	set_param_3(corewar);
}

static void		set_param(t_corewar **corewar)
{
	(*corewar)->the_last_champ = (*corewar)->all_champ->num;
	(*corewar)->cycles = 0;
	(*corewar)->total_cycles = 0;
	(*corewar)->live_operations = 0;
	(*corewar)->checks = 0;
	(*corewar)->cycles_to_die = CYCLE_TO_DIE;
	((*corewar)->operations.delay)[0] = 10;
	((*corewar)->operations.delay)[1] = 5;
	((*corewar)->operations.delay)[2] = 5;
	((*corewar)->operations.delay)[3] = 10;
	((*corewar)->operations.delay)[4] = 10;
	((*corewar)->operations.delay)[5] = 6;
	((*corewar)->operations.delay)[6] = 6;
	((*corewar)->operations.delay)[7] = 6;
	((*corewar)->operations.delay)[8] = 20;
	((*corewar)->operations.delay)[9] = 25;
	((*corewar)->operations.delay)[10] = 25;
	((*corewar)->operations.delay)[11] = 800;
	((*corewar)->operations.delay)[12] = 10;
	((*corewar)->operations.delay)[13] = 50;
	((*corewar)->operations.delay)[14] = 1000;
	((*corewar)->operations.delay)[15] = 2;
	set_param_2(corewar);
}

void			the_game(t_corewar **corewar)
{
	t_carriage		*head;

	set_param(corewar);
	while ((*corewar)->all_carr && (!(*corewar)->flags.dump ||\
			((*corewar)->flags.dump && (*corewar)->total_cycles !=\
			(*corewar)->flags.cycle_num)))
	{
		head = (*corewar)->all_carr;
		(*corewar)->cycles++;
		(*corewar)->total_cycles++;
		the_game_2(corewar, &head);
		(*corewar)->all_carr = head;
		if ((*corewar)->cycles == (*corewar)->cycles_to_die ||\
			(*corewar)->cycles_to_die <= 0)
			cycles_to_die_check(corewar);
	}
	if ((*corewar)->all_carr && (*corewar)->flags.dump)
		print_arena(corewar);
	else
		winner(corewar);
}

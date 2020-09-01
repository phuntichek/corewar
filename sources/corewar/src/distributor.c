/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 05:13:59 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/17 05:14:00 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		operation_distributor_2(t_corewar **corewar, int arg_type,\
			t_carriage **head)
{
	if ((int)(*corewar)->all_carr->operation_code == 9)
		zjmp(corewar);
	else if ((int)(*corewar)->all_carr->operation_code == 10)
		ldi(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 11)
		sti(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 12)
		ft_fork(corewar, head);
	else if ((int)(*corewar)->all_carr->operation_code == 13)
		lld(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 14)
		lldi(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 15)
		lfork(corewar, head);
	else if ((int)(*corewar)->all_carr->operation_code == 1)
		live(corewar);
}

void		operation_distributor(t_corewar **corewar, int arg_type,\
			t_carriage **head)
{
	if ((int)(*corewar)->all_carr->operation_code == 16)
		aff(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 2)
		ld(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 3)
		st(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 4)
		add(corewar);
	else if ((int)(*corewar)->all_carr->operation_code == 5)
		sub(corewar);
	else if ((int)(*corewar)->all_carr->operation_code == 6)
		and(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 7)
		or(corewar, arg_type);
	else if ((int)(*corewar)->all_carr->operation_code == 8)
		xor(corewar, arg_type);
	else
		operation_distributor_2(corewar, arg_type, head);
}

void		skip_operation(t_corewar **corewar, int arg_type, int skip)
{
	int				arg_num;
	int				arg_1;
	int				arg_2;
	int				arg_3;

	arg_num = (*corewar)->\
	operations.arg_num[(int)(*corewar)->all_carr->operation_code - 1];
	arg_1 = (arg_type >> 6) & 3;
	arg_2 = (arg_type >> 4) & 3;
	arg_3 = (arg_type >> 2) & 3;
	if (arg_num > 0)
		skip = skip + get_size(corewar, arg_1);
	if (arg_num > 1)
		skip = skip + get_size(corewar, arg_2);
	if (arg_num > 2)
		skip = skip + get_size(corewar, arg_3);
	(*corewar)->all_carr->position =\
	ft_mod(((*corewar)->all_carr->position + skip), MEM_SIZE);
}

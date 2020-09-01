/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 07:56:58 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/17 07:56:59 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void				ft_fork(t_corewar **corewar, t_carriage **head)
{
	t_carriage	*new_carr;
	int			arg_1;

	arg_1 = ((*corewar)->all_carr->position + 1) % MEM_SIZE;
	arg_1 = get_arg(corewar, arg_1, (*corewar)->operations.t_dir_size[11]);
	arg_1 = ft_mod(((*corewar)->all_carr->position +\
	(arg_1 % IDX_MOD)), MEM_SIZE);
	if (!(new_carr = (t_carriage*)malloc(sizeof(t_carriage))))
		error();
	new_carr->carr_id = (*head)->carr_id + 1;
	new_carr->position = arg_1;
	new_carr->carry = (*corewar)->all_carr->carry;
	new_carr->last_live = (*corewar)->all_carr->last_live;
	arg_1 = 0;
	while (arg_1 < REG_NUMBER)
	{
		(new_carr->reg)[arg_1] = ((*corewar)->all_carr->reg)[arg_1];
		arg_1++;
	}
	new_carr->operation_code = (*corewar)->all_carr->operation_code;
	new_carr->operation_delay = (*corewar)->all_carr->operation_delay;
	new_carr->next = *head;
	*head = new_carr;
	skip_operation(corewar, atc(DIR_CODE, 0, 0), 1);
}

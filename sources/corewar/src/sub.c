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

void		sub(t_corewar **corewar)
{
	int		arg_1;
	int		arg_2;
	int		arg_3;
	int		first_byte;

	first_byte = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	arg_1 = get_arg(corewar, first_byte, T_REG);
	first_byte = (first_byte + T_REG) % MEM_SIZE;
	arg_2 = get_arg(corewar, first_byte, T_REG);
	first_byte = (first_byte + T_REG) % MEM_SIZE;
	arg_3 = get_arg(corewar, first_byte, T_REG);
	arg_1 = ((*corewar)->all_carr->reg)[arg_1 - 1];
	arg_2 = ((*corewar)->all_carr->reg)[arg_2 - 1];
	((*corewar)->all_carr->reg)[arg_3 - 1] = arg_1 - arg_2;
	(*corewar)->all_carr->carry = ((arg_1 - arg_2) == 0 ? true : false);
	skip_operation(corewar, atc(REG_CODE, REG_CODE, REG_CODE), 2);
}

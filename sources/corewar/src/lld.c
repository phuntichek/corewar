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

void		lld(t_corewar **corewar, int arg_type)
{
	int		arg_1;
	int		arg_2;
	int		first_byte;
	int		arg_size;

	first_byte = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	arg_size = get_size(corewar, (arg_type >> 6) & 3);
	arg_1 = get_arg(corewar, first_byte, arg_size);
	first_byte = (first_byte + arg_size) % MEM_SIZE;
	arg_2 = get_arg(corewar, first_byte, T_REG);
	if (((arg_type >> 6) & 3) == IND_CODE)
	{
		first_byte = ft_mod(((*corewar)->all_carr->position + arg_1), MEM_SIZE);
		arg_1 = get_arg(corewar, first_byte, DIR_SIZE);
	}
	((*corewar)->all_carr->reg)[arg_2 - 1] = arg_1;
	(*corewar)->all_carr->carry = (arg_1 == 0 ? true : false);
	skip_operation(corewar, arg_type, 2);
}

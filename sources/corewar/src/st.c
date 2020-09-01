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

void		write_in_mem(t_corewar **corewar, int first_byte, int arg)
{
	((*corewar)->arena)[first_byte] = ((arg >> 24) & 255);
	((*corewar)->arena)[(first_byte + 1) % MEM_SIZE] = ((arg >> 16) & 255);
	((*corewar)->arena)[(first_byte + 2) % MEM_SIZE] = ((arg >> 8) & 255);
	((*corewar)->arena)[(first_byte + 3) % MEM_SIZE] = (arg & 255);
}

void		st(t_corewar **corewar, int arg_type)
{
	int		arg_1;
	int		arg_2;
	int		first_byte;
	int		arg_size;

	first_byte = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	arg_1 = get_arg(corewar, first_byte, T_REG);
	arg_1 = ((*corewar)->all_carr->reg)[arg_1 - 1];
	arg_size = get_size(corewar, (arg_type >> 4) & 3);
	first_byte = (first_byte + T_REG) % MEM_SIZE;
	arg_2 = get_arg(corewar, first_byte, arg_size);
	if (((arg_type >> 4) & 3) == IND_CODE)
	{
		first_byte = ft_mod(((*corewar)->all_carr->position +\
		(arg_2 % IDX_MOD)), MEM_SIZE);
		write_in_mem(corewar, first_byte, arg_1);
	}
	else
		((*corewar)->all_carr->reg)[arg_2 - 1] = arg_1;
	skip_operation(corewar, arg_type, 2);
}

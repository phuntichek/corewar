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

static int	get_arg_sti(t_corewar **corewar, int arg_type,\
			int *first_byte, int *arg_size)
{
	int		arg_2;
	int		arg_3;

	*first_byte = ((*corewar)->all_carr->position + 2 + T_REG) % MEM_SIZE;
	*arg_size = get_size(corewar, (arg_type >> 4) & 3);
	arg_2 = get_arg(corewar, *first_byte, *arg_size);
	if (((arg_type >> 4) & 3) == REG_CODE)
		arg_2 = ((*corewar)->all_carr->reg)[arg_2 - 1];
	else if (((arg_type >> 4) & 3) == IND_CODE)
	{
		*first_byte = ft_mod(((*corewar)->all_carr->position +\
		(arg_2 % IDX_MOD)), MEM_SIZE);
		arg_2 = get_arg(corewar, *first_byte, DIR_SIZE);
	}
	*first_byte = ((*corewar)->all_carr->position + 2 +\
	T_REG + *arg_size) % MEM_SIZE;
	*arg_size = get_size(corewar, (arg_type >> 2) & 3);
	arg_3 = get_arg(corewar, *first_byte, *arg_size);
	if (((arg_type >> 2) & 3) == REG_CODE)
		arg_3 = ((*corewar)->all_carr->reg)[arg_3 - 1];
	return (ft_mod(((*corewar)->all_carr->position +\
	((arg_2 + arg_3) % IDX_MOD)), MEM_SIZE));
}

void		sti(t_corewar **corewar, int arg_type)
{
	int		arg_1;
	int		arg_2;
	int		first_byte;
	int		arg_size;

	first_byte = 0;
	arg_size = 0;
	arg_2 = get_arg_sti(corewar, arg_type, &first_byte, &arg_size);
	first_byte = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	arg_1 = get_arg(corewar, first_byte, T_REG);
	arg_1 = ((*corewar)->all_carr->reg)[arg_1 - 1];
	write_in_mem(corewar, arg_2, arg_1);
	skip_operation(corewar, arg_type, 2);
}

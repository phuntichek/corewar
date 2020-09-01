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

int			atc(int arg_1, int arg_2, int arg_3)
{
	int		arg_type;

	arg_type = 0;
	arg_type = (arg_type | arg_1) << 2;
	arg_type = (arg_type | arg_2) << 2;
	arg_type = (arg_type | arg_3) << 2;
	return (arg_type);
}

int			get_arg_minus(int arg, int arg_size)
{
	int		out;
	int		mask;
	int		size;

	out = 0;
	mask = 0;
	size = 32 - (arg_size * 8) - 1;
	while (size >= 0)
	{
		mask = mask << 1;
		mask = mask | 1;
		size--;
	}
	mask = (mask << (arg_size * 8));
	out = arg | mask;
	return (out);
}

int			get_arg(t_corewar **corewar, int first_byte, int arg_size)
{
	int		arg;
	int		byte;
	int		size;

	arg = 0;
	size = 0;
	while (size < arg_size)
	{
		byte = (int)((*corewar)->arena)[(first_byte + size) % MEM_SIZE];
		arg = (arg | byte);
		size++;
		if (size < arg_size)
			arg = arg << 8;
	}
	size = arg_size * 8 - 1;
	if ((((arg >> size) & 1) == 1) && arg_size < 4)
		arg = get_arg_minus(arg, arg_size);
	return (arg);
}

void		live(t_corewar **corewar)
{
	int		arg_1;

	arg_1 = ((*corewar)->all_carr->position + 1) % MEM_SIZE;
	arg_1 = get_arg(corewar, arg_1, (*corewar)->operations.t_dir_size[0]);
	if (arg_1 < 0 && arg_1 >= ((*corewar)->all_champ->num * -1))
		(*corewar)->the_last_champ = arg_1 * -1;
	(*corewar)->all_carr->last_live = (*corewar)->total_cycles;
	(*corewar)->live_operations++;
	skip_operation(corewar, atc(DIR_CODE, 0, 0), 1);
}

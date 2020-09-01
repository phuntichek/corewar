/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 05:08:11 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/17 05:08:13 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		get_size(t_corewar **corewar, int arg)
{
	int		i;

	i = (int)((*corewar)->all_carr->operation_code) - 1;
	if (arg == REG_CODE)
		return (T_REG);
	if (arg == DIR_CODE)
		return (((*corewar)->operations.t_dir_size)[i]);
	if (arg == IND_CODE)
		return (IND_SIZE);
	return (0);
}

int		check_registr_2(t_corewar **corewar, int arg_1, int arg_2, int arg_3)
{
	unsigned char	reg;
	int				size;
	int				reg_pos;

	size = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	if (arg_2 == REG_CODE)
	{
		reg_pos = (size + get_size(corewar, arg_1)) % MEM_SIZE;
		reg = (*corewar)->arena[reg_pos];
		if (!(reg >= 1 && reg <= REG_NUMBER))
			return (0);
	}
	if (arg_3 == REG_CODE)
	{
		reg_pos = (size + get_size(corewar, arg_1) +\
		get_size(corewar, arg_2)) % MEM_SIZE;
		reg = (*corewar)->arena[reg_pos];
		if (!(reg >= 1 && reg <= REG_NUMBER))
			return (0);
	}
	return (1);
}

int		check_registr(t_corewar **corewar, int arg_type)
{
	unsigned char	reg;
	int				size;
	int				arg_1;
	int				arg_2;
	int				arg_3;

	arg_1 = (arg_type >> 6) & 3;
	arg_2 = (arg_type >> 4) & 3;
	arg_3 = (arg_type >> 2) & 3;
	size = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
	if (arg_1 == REG_CODE)
	{
		reg = (*corewar)->arena[size];
		if (!(reg >= 1 && reg <= REG_NUMBER))
			return (0);
	}
	return (check_registr_2(corewar, arg_1, arg_2, arg_3));
}

int		kick_bit(t_corewar **corewar)
{
	int		arg_type;

	arg_type = 0;
	if ((*corewar)->operations.arg_num[(int)\
		(*corewar)->all_carr->operation_code - 1] == 1)
		arg_type = (int)(*corewar)->arena[((*corewar)->all_carr->position +\
		1) % MEM_SIZE] & KICK_BIT_1;
	else if ((*corewar)->operations.arg_num[(int)\
			(*corewar)->all_carr->operation_code - 1] == 2)
		arg_type = (int)(*corewar)->arena[((*corewar)->all_carr->position +\
		1) % MEM_SIZE] & KICK_BIT_2;
	else if ((*corewar)->operations.arg_num[(int)\
			(*corewar)->all_carr->operation_code - 1] == 3)
		arg_type = (int)(*corewar)->arena[((*corewar)->all_carr->position +\
		1) % MEM_SIZE] & KICK_BIT_3;
	return (arg_type);
}

void	pre_execute(t_corewar **corewar, t_carriage **head)
{
	int			arg_type;

	arg_type = kick_bit(corewar);
	if ((int)(*corewar)->all_carr->operation_code >= 1 &&\
		(int)(*corewar)->all_carr->operation_code <= 16)
	{
		if ((*corewar)->operations.arg_type[(int)\
			(*corewar)->all_carr->operation_code - 1])
		{
			if ((*corewar)->operations.arg_valid[\
				(*corewar)->all_carr->operation_code - 1][arg_type])
			{
				if ((arg_type >> 2 & 3) == REG_CODE || (arg_type >> 4 & 3) ==\
					REG_CODE || (arg_type >> 6 & 3) == REG_CODE)
					if (!check_registr(corewar, arg_type))
						return (skip_operation(corewar, arg_type, 2));
			}
			else
				return (skip_operation(corewar, arg_type, 2));
		}
		operation_distributor(corewar, arg_type, head);
	}
	else
		(*corewar)->all_carr->position =\
		((*corewar)->all_carr->position + 1) % MEM_SIZE;
}

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

int			ft_mod(int arg_1, int arg_2)
{
	if (arg_1 >= 0)
		return (arg_1 % arg_2);
	else
		return ((arg_1 % arg_2) + arg_2);
}

void		zjmp(t_corewar **corewar)
{
	int		arg_1;

	if ((*corewar)->all_carr->carry)
	{
		arg_1 = ((*corewar)->all_carr->position + 1) % MEM_SIZE;
		arg_1 = get_arg(corewar, arg_1, (*corewar)->operations.t_dir_size[8]);
		(*corewar)->all_carr->position = ft_mod(((*corewar)->all_carr->position\
		+ (arg_1 % IDX_MOD)), MEM_SIZE);
	}
	else
		skip_operation(corewar, atc(DIR_CODE, 0, 0), 1);
}

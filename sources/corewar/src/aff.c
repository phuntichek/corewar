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

void		aff(t_corewar **corewar, int arg_type)
{
	int		arg_1;
	int		first_byte;
	char	print;

	if ((*corewar)->flags.aff)
	{
		first_byte = ((*corewar)->all_carr->position + 2) % MEM_SIZE;
		arg_1 = get_arg(corewar, first_byte, T_REG);
		print = (char)(((*corewar)->all_carr->reg)[arg_1 - 1]);
		write(1, "Aff: ", 5);
		write(1, &print, 1);
		write(1, "\n", 1);
	}
	skip_operation(corewar, arg_type, 2);
}

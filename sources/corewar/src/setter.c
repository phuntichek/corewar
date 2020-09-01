/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:47:23 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/16 22:47:24 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		set_param_2(t_corewar **corewar)
{
	((*corewar)->operations.t_dir_size)[7] = 4;
	((*corewar)->operations.t_dir_size)[8] = 2;
	((*corewar)->operations.t_dir_size)[9] = 2;
	((*corewar)->operations.t_dir_size)[10] = 2;
	((*corewar)->operations.t_dir_size)[11] = 2;
	((*corewar)->operations.t_dir_size)[12] = 4;
	((*corewar)->operations.t_dir_size)[13] = 2;
	((*corewar)->operations.t_dir_size)[14] = 2;
	((*corewar)->operations.t_dir_size)[15] = 4;
}

static void		set_param(t_corewar **corewar)
{
	int		i;

	((*corewar)->operations.arg_valid)[5][148] = true;
	((*corewar)->operations.arg_valid)[5][164] = true;
	((*corewar)->operations.arg_valid)[5][180] = true;
	((*corewar)->operations.arg_valid)[5][212] = true;
	((*corewar)->operations.arg_valid)[5][228] = true;
	((*corewar)->operations.arg_valid)[5][244] = true;
	i = 84;
	while (i < 245)
	{
		((*corewar)->operations.arg_valid)[6][i] =\
			((*corewar)->operations.arg_valid)[5][i];
		((*corewar)->operations.arg_valid)[7][i] =\
			((*corewar)->operations.arg_valid)[5][i];
		i++;
	}
	((*corewar)->operations.t_dir_size)[0] = 4;
	((*corewar)->operations.t_dir_size)[1] = 4;
	((*corewar)->operations.t_dir_size)[2] = 4;
	((*corewar)->operations.t_dir_size)[3] = 4;
	((*corewar)->operations.t_dir_size)[4] = 4;
	((*corewar)->operations.t_dir_size)[5] = 4;
	((*corewar)->operations.t_dir_size)[6] = 4;
	set_param_2(corewar);
}

void			setter(t_corewar **corewar)
{
	int		i;

	((*corewar)->operations.arg_valid)[9][84] = true;
	((*corewar)->operations.arg_valid)[9][100] = true;
	((*corewar)->operations.arg_valid)[9][148] = true;
	((*corewar)->operations.arg_valid)[9][164] = true;
	((*corewar)->operations.arg_valid)[9][212] = true;
	((*corewar)->operations.arg_valid)[9][228] = true;
	i = 84;
	while (i < 229)
	{
		((*corewar)->operations.arg_valid)[13][i] =\
			((*corewar)->operations.arg_valid)[9][i];
		i++;
	}
	((*corewar)->operations.arg_valid)[10][84] = true;
	((*corewar)->operations.arg_valid)[10][88] = true;
	((*corewar)->operations.arg_valid)[10][100] = true;
	((*corewar)->operations.arg_valid)[10][104] = true;
	((*corewar)->operations.arg_valid)[10][116] = true;
	((*corewar)->operations.arg_valid)[10][120] = true;
	((*corewar)->operations.arg_valid)[5][84] = true;
	((*corewar)->operations.arg_valid)[5][100] = true;
	((*corewar)->operations.arg_valid)[5][116] = true;
	set_param(corewar);
}

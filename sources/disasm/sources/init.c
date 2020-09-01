/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschmele <fmelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:29:11 by rschmele          #+#    #+#             */
/*   Updated: 2019/04/12 16:28:42 by rschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_dasm			*init_dasm(void)
{
	t_dasm		*dasm;

	if (!(dasm = (t_dasm *)malloc(sizeof(t_dasm))))
		exit(EXIT_FAILURE);
	dasm->com = NULL;
	dasm->code = NULL;
	dasm->comment = NULL;
	dasm->name = NULL;
	dasm->code_size = 0;
	dasm->in = 0;
	dasm->head = 0;
	return (dasm);
}

t_com			*init_new_node(void)
{
	t_com		*node;

	if (!(node = (t_com *)malloc(sizeof(t_com))))
		exit(EXIT_FAILURE);
	node->arg = NULL;
	node->name = NULL;
	node->next = NULL;
	node->t_arg = NULL;
	return (node);
}

bool			init_command(uint8_t op, t_com **com)
{
	if (op >= 0x01 && op <= 0x10)
	{
		if (op == 0x01)
		{
			(*com)->name = ft_strdup("live");
			(*com)->type = false;
			(*com)->am_arg = 1;
			(*com)->dir_size = 4;
		}
		if (op == 0x02)
		{
			(*com)->name = ft_strdup("ld");
			(*com)->type = true;
			(*com)->am_arg = 2;
			(*com)->dir_size = 4;
		}
		init_command1(op, com);
		init_command2(op, com);
		init_command3(op, com);
		init_command4(op, com);
		init_command5(op, com);
		return (true);
	}
	return (false);
}

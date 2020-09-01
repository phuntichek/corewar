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

void			init_command1(uint8_t op, t_com **com)
{
	if (op == 0x04)
	{
		(*com)->name = ft_strdup("add");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 4;
	}
	if (op == 0x05)
	{
		(*com)->name = ft_strdup("sub");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 4;
	}
	if (op == 0x06)
	{
		(*com)->name = ft_strdup("and");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 4;
	}
}

void			init_command2(uint8_t op, t_com **com)
{
	if (op == 0x07)
	{
		(*com)->name = ft_strdup("or");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 4;
	}
	if (op == 0x08)
	{
		(*com)->name = ft_strdup("xor");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 4;
	}
	if (op == 0x09)
	{
		(*com)->name = ft_strdup("zjmp");
		(*com)->type = false;
		(*com)->am_arg = 1;
		(*com)->dir_size = 2;
	}
}

void			init_command3(uint8_t op, t_com **com)
{
	if (op == 0x0a)
	{
		(*com)->name = ft_strdup("ldi");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 2;
	}
	if (op == 0x0b)
	{
		(*com)->name = ft_strdup("sti");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 2;
	}
	if (op == 0x0c)
	{
		(*com)->name = ft_strdup("fork");
		(*com)->type = false;
		(*com)->am_arg = 1;
		(*com)->dir_size = 2;
	}
}

void			init_command4(uint8_t op, t_com **com)
{
	if (op == 0x0d)
	{
		(*com)->name = ft_strdup("lld");
		(*com)->type = true;
		(*com)->am_arg = 2;
		(*com)->dir_size = 4;
	}
	if (op == 0x0e)
	{
		(*com)->name = ft_strdup("lldi");
		(*com)->type = true;
		(*com)->am_arg = 3;
		(*com)->dir_size = 2;
	}
	if (op == 0x0f)
	{
		(*com)->name = ft_strdup("lfork");
		(*com)->type = false;
		(*com)->am_arg = 1;
		(*com)->dir_size = 2;
	}
}

void			init_command5(uint8_t op, t_com **com)
{
	if (op == 0x10)
	{
		(*com)->name = ft_strdup("aff");
		(*com)->type = true;
		(*com)->am_arg = 1;
		(*com)->dir_size = 4;
	}
	if (op == 0x03)
	{
		(*com)->name = ft_strdup("st");
		(*com)->type = true;
		(*com)->am_arg = 2;
		(*com)->dir_size = 4;
	}
}

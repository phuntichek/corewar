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

void			parse_magic(int fd)
{
	uint8_t		buf[4];
	int			size;
	size_t		res;

	size = read(fd, &buf, 4);
	if (size == -1 && size < 4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	if (res != COREWAR_EXEC_MAGIC)
	{
		ft_putstr("Wrong magic number\n");
		exit(EXIT_FAILURE);
	}
}

void			parse_name(int fd, t_dasm *dasm)
{
	char		*buf;
	int			size;

	buf = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	size = read(fd, buf, PROG_NAME_LENGTH);
	if (size == -1)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	dasm->name = ft_strdup(buf);
	free(buf);
}

void			parse_null(int fd)
{
	uint8_t		buf[4];
	int			size;
	int			res;

	size = read(fd, &buf, 4);
	if (size == -1 && size < 4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	if (res != 0)
	{
		ft_putrstr("no null\n");
		exit(EXIT_FAILURE);
	}
}

void			parse_code_size(int fd, t_dasm *dasm)
{
	uint8_t		buf[4];
	size_t		size;
	int			res;

	size = read(fd, &buf, 4);
	if (size == (size_t)-1 && size < (size_t)4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	if (res > CHAMP_MAX_SIZE)
	{
		ft_putstr("Wrong champion code size\n");
		exit(EXIT_FAILURE);
	}
	dasm->code_size = res;
}

void			parse_comment(int fd, t_dasm *dasm)
{
	char		*buf;
	int			size;

	buf = ft_strnew(COMMENT_LENGTH);
	size = read(fd, buf, COMMENT_LENGTH);
	if (size == -1)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	dasm->comment = ft_strdup(buf);
	free(buf);
}

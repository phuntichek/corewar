/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:16:24 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/09 17:16:26 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		pars_help(t_champions **new_champ, unsigned char *exec_code,\
				int code_size, unsigned char *buf)
{
	int		i;

	if (exec_code)
	{
		if (!((*new_champ)->exec_code =\
			(unsigned char*)malloc(sizeof(unsigned char) * code_size)))
			error();
	}
	else
		(*new_champ)->exec_code = NULL;
	i = -1;
	while (++i < code_size)
		(*new_champ)->exec_code[i] = exec_code[i];
	i = 4;
	while (buf[i] != '\0')
		i++;
	if (!((*new_champ)->name = (unsigned char*)malloc(sizeof(unsigned char) *\
		(i - 4 + 1))))
		error();
	while (i > 3)
	{
		(*new_champ)->name[i - 4] = buf[i];
		i--;
	}
}

void			pars_champ_param(t_corewar **corewar, unsigned char *exec_code,\
				unsigned char *buf, int current_num)
{
	int			i;
	int			code_size;
	t_champions	*new_champ;

	code_size = oper(buf, 136);
	if (!(new_champ = (t_champions*)malloc(sizeof(t_champions))))
		error();
	new_champ->num = current_num;
	new_champ->code_size = code_size;
	pars_help(&new_champ, exec_code, code_size, buf);
	i = 140;
	while (buf[i] != '\0')
		i++;
	if (!(new_champ->comment = (unsigned char*)malloc(sizeof(unsigned char) *\
		(i - 140 + 1))))
		error();
	while (i > 139)
	{
		new_champ->comment[i - 140] = buf[i];
		i--;
	}
	new_champ->next = (*corewar)->all_champ;
	(*corewar)->all_champ = new_champ;
}

int				oper(unsigned char *buf, int start)
{
	int		out;

	out = 0;
	out = (out | buf[start]) << 8;
	out = (out | buf[start + 1]) << 8;
	out = (out | buf[start + 2]) << 8;
	out = (out | buf[start + 3]);
	return (out);
}

static void		valid_help(t_corewar **corewar, int current_num)
{
	if (current_num > MAX_PLAYERS)
		print_usage(corewar, 1);
}

void			validator(t_corewar **corewar,\
				t_reader **champ, int current_num)
{
	int				fd;
	unsigned char	buf[BYTE_CODE_HEAD];
	unsigned char	*exec_code;

	valid_help(corewar, current_num);
	if ((fd = open((*champ)->path, O_RDONLY)) < 0)
		print_usage(corewar, 4);
	if ((int)read(fd, buf, BYTE_CODE_HEAD) < (int)BYTE_CODE_HEAD)
		print_usage(corewar, 5);
	if (COREWAR_EXEC_MAGIC != oper(buf, 0))
		print_usage(corewar, 6);
	if (oper(buf, 132) != 0 || oper(buf, 2188) != 0)
		print_usage(corewar, 7);
	if (oper(buf, 136) > CHAMP_MAX_SIZE || oper(buf, 136) < 0)
		print_usage(corewar, 8);
	if (oper(buf, 136) == 0)
		exec_code = NULL;
	else
	{
		exec_code = (unsigned char*)(*gc_malloc(sizeof(unsigned char) *\
		(oper(buf, 136) + 1)));
		if (read(fd, exec_code, oper(buf, 136) + 1) != oper(buf, 136))
			print_usage(corewar, 9);
	}
	pars_champ_param(corewar, exec_code, buf, current_num);
}

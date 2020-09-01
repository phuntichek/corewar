/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:53:27 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/08 15:53:30 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	dump_flag(char **argv, int argc, int *ac, t_corewar **corewar)
{
	int		i;

	if ((*corewar)->flags.dump)
		print_usage(corewar, 2);
	(*corewar)->flags.dump = true;
	if (!ft_strcmp(argv[*ac], "-dump"))
		(*corewar)->flags.print_style = 32;
	else if (!ft_strcmp(argv[*ac], "-d"))
		(*corewar)->flags.print_style = 64;
	*ac += 1;
	if (*ac >= argc)
		print_usage(corewar, 3);
	i = 0;
	while (argv[*ac][i] != '\0')
	{
		if (!(argv[*ac][i] >= '0' && argv[*ac][i] <= '9'))
			print_usage(corewar, 3);
		i++;
	}
	(*corewar)->flags.cycle_num = ft_atoi(argv[*ac]);
	if ((*corewar)->flags.cycle_num < 0)
		print_usage(corewar, 3);
}

int		number_flag(char **argv, int argc, int *ac, t_reader **with_flag)
{
	int		i;
	int		num;

	*ac += 1;
	if (*ac >= argc || ((*ac + 1) >= argc))
		return (1);
	i = 0;
	while (argv[*ac][i] != '\0')
	{
		if (!(argv[*ac][i] >= '0' && argv[*ac][i] <= '9'))
			return (1);
		i++;
	}
	num = ft_atoi(argv[*ac]);
	if (num < 0 || num > MAX_PLAYERS)
		return (1);
	*ac += 1;
	push_arg(with_flag, argv[*ac], num);
	return (0);
}

void	push_arg(t_reader **arg_list, char *path, int num)
{
	t_reader	*new_arg;

	if (arg_list)
	{
		new_arg = (t_reader*)(*gc_malloc(sizeof(t_reader)));
		new_arg->num = num;
		new_arg->path = path;
		new_arg->next = *arg_list;
		*arg_list = new_arg;
	}
	else
		error();
}

void	arguments_reader_2(t_corewar **corewar, char **argv, int argc, int *ac)
{
	if (!ft_strcmp(argv[*ac], "-a"))
	{
		if ((*corewar)->flags.aff)
			print_usage(corewar, 2);
		(*corewar)->flags.aff = true;
	}
	else if (!ft_strcmp(argv[*ac], "-d") || !ft_strcmp(argv[*ac], "-dump"))
		dump_flag(argv, argc, ac, corewar);
	else
		print_usage(corewar, 3);
}

void	arguments_reader(int argc, char **argv, t_corewar **corewar)
{
	int			ac;
	t_reader	*no_flag;
	t_reader	*with_flag;

	ac = 1;
	no_flag = NULL;
	with_flag = NULL;
	while (ac < argc)
	{
		if (argv[ac][0] == '-')
		{
			if (!ft_strcmp(argv[ac], "-n"))
			{
				if (number_flag(argv, argc, &ac, &with_flag))
					print_usage(corewar, 3);
			}
			else
				arguments_reader_2(corewar, argv, argc, &ac);
		}
		else
			push_arg(&no_flag, argv[ac], 0);
		ac++;
	}
	bytecode_reader(&no_flag, &with_flag, corewar);
}

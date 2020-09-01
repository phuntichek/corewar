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

void			find_in_no(t_corewar **corewar,\
				t_reader **no_flag, int current_num)
{
	t_reader	*head;

	if (*no_flag == NULL)
		print_usage(corewar, 3);
	head = *no_flag;
	if (*no_flag && (*no_flag)->next == NULL)
	{
		validator(corewar, &head, current_num);
		*no_flag = NULL;
		return ;
	}
	while ((*no_flag)->next != NULL && (*no_flag)->next->next != NULL)
		*no_flag = (*no_flag)->next;
	validator(corewar, &((*no_flag)->next), current_num);
	(*no_flag)->next = NULL;
	*no_flag = head;
}

static void		with_help_2(t_corewar **corewar, t_reader **with_flag,\
				t_reader **prev, int current_num)
{
	(*prev)->next = (*with_flag)->next;
	(*with_flag)->next = NULL;
	validator(corewar, &(*with_flag), current_num);
}

static void		with_help_1(t_corewar **corewar, t_reader **with_flag,\
				t_reader **head, int current_num)
{
	(*with_flag) = (*with_flag)->next;
	(*head)->next = NULL;
	validator(corewar, head, current_num);
}

int				find_in_with(t_corewar **corewar,\
				t_reader **with_flag, int current_num)
{
	t_reader	*head;
	t_reader	*prev;

	head = *with_flag;
	prev = NULL;
	while (*with_flag != NULL)
	{
		if ((*with_flag)->num < current_num)
			print_usage(corewar, 3);
		if ((*with_flag)->num == current_num)
		{
			if (prev == NULL)
				with_help_1(corewar, with_flag, &head, current_num);
			else
			{
				with_help_2(corewar, with_flag, &prev, current_num);
				*with_flag = head;
			}
			return (1);
		}
		prev = *with_flag;
		*with_flag = (*with_flag)->next;
	}
	*with_flag = head;
	return (0);
}

void			bytecode_reader(t_reader **no_flags,\
				t_reader **with_flag, t_corewar **corewar)
{
	int			current_num;

	current_num = 1;
	if (*with_flag == NULL && *no_flags == NULL)
		print_usage(corewar, 1);
	while (*with_flag != NULL)
	{
		if (find_in_with(corewar, with_flag, current_num))
			;
		else
			find_in_no(corewar, no_flags, current_num);
		current_num++;
	}
	while (*no_flags != NULL)
	{
		find_in_no(corewar, no_flags, current_num);
		current_num++;
	}
}

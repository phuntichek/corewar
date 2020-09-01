/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:26:49 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/11 21:26:50 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void			winner(t_corewar **corewar)
{
	t_champions		*head;
	char			*itoa;

	head = (*corewar)->all_champ;
	while ((*corewar)->all_champ && (*corewar)->all_champ->num !=\
	(*corewar)->the_last_champ)
		(*corewar)->all_champ = (*corewar)->all_champ->next;
	if ((*corewar)->all_champ)
	{
		write(1, "Contestant ", 11);
		itoa = ft_itoa((*corewar)->the_last_champ);
		write(1, itoa, ft_numlen((*corewar)->the_last_champ));
		free(itoa);
		write(1, ", \"", 3);
		write(1, (*corewar)->all_champ->name,\
		ft_strlen((const char*)(*corewar)->all_champ->name));
		write(1, "\", has won !\n", 13);
	}
	else
		error();
	(*corewar)->all_champ = head;
}

static void		intro_help(t_corewar **corewar)
{
	char			*itoa;

	write(1, "* Player ", 9);
	itoa = ft_itoa((*corewar)->all_champ->num);
	write(1, itoa, ft_numlen((*corewar)->all_champ->num));
	free(itoa);
	write(1, ", weighing ", 11);
	itoa = ft_itoa((*corewar)->all_champ->code_size);
	write(1, itoa, ft_numlen((*corewar)->all_champ->code_size));
	free(itoa);
	write(1, " bytes, \"", 9);
	write(1, (*corewar)->all_champ->name,\
	ft_strlen((const char*)(*corewar)->all_champ->name));
	write(1, "\" (\"", 4);
	write(1, (*corewar)->all_champ->comment,\
	ft_strlen((const char*)(*corewar)->all_champ->comment));
	write(1, "\") !\n", 5);
}

void			intro_contestants(t_corewar **corewar)
{
	int				champ_num;
	t_champions		*head;

	write(1, "Introducing contestants...\n", 27);
	champ_num = 1;
	head = (*corewar)->all_champ;
	while (champ_num <= head->num)
	{
		while ((*corewar)->all_champ->num != champ_num)
			(*corewar)->all_champ = (*corewar)->all_champ->next;
		intro_help(corewar);
		(*corewar)->all_champ = head;
		champ_num++;
	}
}

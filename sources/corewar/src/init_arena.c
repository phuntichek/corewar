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

static void		init_carr_help(t_carriage **new_carr,\
				int position, int champ_num)
{
	(*new_carr)->carr_id = champ_num;
	(*new_carr)->position = position;
	(*new_carr)->carry = false;
	(*new_carr)->last_live = 0;
	(*new_carr)->operation_code = 0;
	(*new_carr)->operation_delay = 0;
	((*new_carr)->reg)[0] = champ_num * -1;
	(*new_carr)->next = NULL;
}

void			init_carriages(t_corewar **corewar, int position, int champ_num)
{
	t_carriage	*new_carr;
	t_carriage	*head;
	int			i;

	if (!(new_carr = (t_carriage*)malloc(sizeof(t_carriage))))
		error();
	init_carr_help(&new_carr, position, champ_num);
	i = 1;
	while (i < REG_NUMBER)
		(new_carr->reg)[i++] = 0;
	if ((*corewar)->all_carr == NULL)
		(*corewar)->all_carr = new_carr;
	else
	{
		head = (*corewar)->all_carr;
		while ((*corewar)->all_carr->next != NULL)
			(*corewar)->all_carr = (*corewar)->all_carr->next;
		(*corewar)->all_carr->next = new_carr;
		(*corewar)->all_carr = head;
	}
}

void			arena_filler(t_corewar **corewar, unsigned char *filler,\
				int start, int size)
{
	int		i;

	i = 0;
	if (filler == NULL)
		while (i < size)
		{
			((*corewar)->arena)[start + i] = 0;
			i++;
		}
	else
		while (i < size)
		{
			((*corewar)->arena)[start + i] = filler[i];
			i++;
		}
}

void			init_arena(t_corewar **corewar)
{
	t_champions		*head;
	int				champ_position;

	if (!((*corewar)->arena = (unsigned char*)malloc((int)MEM_SIZE)))
		error();
	arena_filler(corewar, NULL, 0, MEM_SIZE);
	head = (*corewar)->all_champ;
	while ((*corewar)->all_champ != NULL)
	{
		champ_position = MEM_SIZE / head->num *\
		((*corewar)->all_champ->num - 1);
		if (champ_position + (*corewar)->all_champ->code_size > MEM_SIZE ||\
		CHAMP_MAX_SIZE > MEM_SIZE / head->num)
			print_usage(corewar, 10);
		arena_filler(corewar, (*corewar)->all_champ->exec_code, champ_position,\
		(*corewar)->all_champ->code_size);
		init_carriages(corewar, champ_position, (*corewar)->all_champ->num);
		(*corewar)->all_champ = (*corewar)->all_champ->next;
	}
	(*corewar)->all_champ = head;
}

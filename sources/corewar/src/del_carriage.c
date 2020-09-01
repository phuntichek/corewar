/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 05:10:44 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/17 05:10:45 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		after_check(t_corewar **corewar)
{
	if ((*corewar)->live_operations >= NBR_LIVE ||\
		(*corewar)->checks == MAX_CHECKS)
	{
		(*corewar)->cycles_to_die -= CYCLE_DELTA;
		(*corewar)->checks = 0;
	}
	(*corewar)->cycles = 0;
	(*corewar)->live_operations = 0;
}

void			cycles_to_die_check(t_corewar **corewar)
{
	t_carriage	*head;
	t_carriage	*prev;

	(*corewar)->checks++;
	head = (*corewar)->all_carr;
	prev = NULL;
	while ((*corewar)->all_carr)
	{
		if ((*corewar)->total_cycles - (*corewar)->all_carr->last_live >=\
			(*corewar)->cycles_to_die || (*corewar)->cycles_to_die <= 0)
		{
			del_carriage(&prev, &head, corewar);
			if (prev && (*corewar)->all_carr)
				(*corewar)->all_carr = (*corewar)->all_carr->next;
		}
		else
		{
			prev = (*corewar)->all_carr;
			if ((*corewar)->all_carr)
				(*corewar)->all_carr = (*corewar)->all_carr->next;
		}
	}
	(*corewar)->all_carr = head;
	after_check(corewar);
}

void			free_carriages(t_corewar **corewar)
{
	t_carriage		*del;

	while ((*corewar)->all_carr)
	{
		del = (*corewar)->all_carr;
		(*corewar)->all_carr = (*corewar)->all_carr->next;
		del->next = NULL;
		free(del);
		del = NULL;
	}
}

void			del_carriage(t_carriage **prev,\
				t_carriage **head, t_corewar **corewar)
{
	t_carriage *next;

	if ((*corewar)->all_carr == *head)
		*head = (*corewar)->all_carr->next;
	next = (*corewar)->all_carr->next;
	(*corewar)->all_carr->next = NULL;
	free((*corewar)->all_carr);
	(*corewar)->all_carr = next;
	if (*prev != NULL)
	{
		(*prev)->next = (*corewar)->all_carr;
		(*corewar)->all_carr = *prev;
	}
}

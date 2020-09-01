/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:08:34 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/14 18:08:38 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void			the_game_2(t_corewar **corewar, t_carriage **head)
{
	while ((*corewar)->all_carr)
	{
		if ((*corewar)->all_carr->operation_delay == 0)
		{
			(*corewar)->all_carr->operation_code =\
			((*corewar)->arena)[(*corewar)->all_carr->position];
			if ((int)(*corewar)->all_carr->operation_code >= 1 &&\
				(int)(*corewar)->all_carr->operation_code <= 16)
				(*corewar)->all_carr->operation_delay =\
((*corewar)->operations.delay)[(int)(*corewar)->all_carr->operation_code - 1];
		}
		if ((*corewar)->all_carr->operation_delay > 0)
			(*corewar)->all_carr->operation_delay--;
		if ((*corewar)->all_carr->operation_delay == 0)
			pre_execute(corewar, head);
		(*corewar)->all_carr = (*corewar)->all_carr->next;
	}
}

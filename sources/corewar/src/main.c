/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:58:05 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/08 15:58:07 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		set_param(t_corewar **corewar)
{
	(*corewar)->flags.dump = false;
	(*corewar)->flags.aff = false;
	(*corewar)->flags.cycle_num = 0;
	(*corewar)->flags.print_style = 0;
}

void			free_champ(t_corewar **corewar)
{
	t_champions		*del;

	while ((*corewar)->all_champ)
	{
		del = (*corewar)->all_champ;
		(*corewar)->all_champ = (*corewar)->all_champ->next;
		del->next = NULL;
		free(del->exec_code);
		free(del->name);
		free(del->comment);
		free(del);
		del = NULL;
	}
}

int				main(int argc, char **argv)
{
	t_corewar	*corewar;

	g_memory = NULL;
	corewar = (t_corewar*)malloc(sizeof(t_corewar));
	corewar->all_champ = NULL;
	corewar->arena = NULL;
	corewar->all_carr = NULL;
	set_param(&corewar);
	if (argc < 2)
		print_usage(&corewar, 1);
	arguments_reader(argc, argv, &corewar);
	init_arena(&corewar);
	intro_contestants(&corewar);
	gc_free();
	the_game(&corewar);
	free_carriages(&corewar);
	free(corewar->arena);
	free_champ(&corewar);
	free(corewar);
	return (0);
}

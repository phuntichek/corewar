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

void	usage_out(void)
{
	write(1, "Usage: ./corewar [-d N -dump N -a] ", 35);
	write(1, "[-n N] <champion_1.cor> <...>\n", 30);
	write(1, "   -d N     : Dump memory after N cycles ", 41);
	write(1, "then exit (print 64 bytes per line)\n", 36);
	write(1, "   -dump N  : Dump memory after N cycles ", 41);
	write(1, "then exit (print 32 bytes per line)\n", 36);
	write(1, "   -a       : Print output from \"aff\" (Default hidden)\n", 55);
	write(1, "   -n N     : Set the number of the champion\n", 45);
}

void	print_usage_2(int flag)
{
	if (flag == 1)
		usage_out();
	else if (flag == 2)
		write(1, "Error: Dublicate flag\n", 22);
	else if (flag == 3)
	{
		write(1, "Error: Invalid flag\n", 20);
		usage_out();
	}
	else if (flag == 4)
		write(1, "Error: Invalid name of champion\n", 32);
	else if (flag == 5)
		write(1, "Error: Invalid champion's header\n", 33);
	else if (flag == 6)
		write(1, "Error: Invalid champion's EXEC_MAGIC\n", 37);
	else if (flag == 7)
		write(1, "Error: Bad code check point (isn't equal to 0)\n", 47);
	else if (flag == 8)
		write(1, "Error: Champion's code > CHAMP_MAX_SIZE\n", 40);
	else if (flag == 9)
		write(1, "Error: The code size is not equal to header code size\n", 54);
	else if (flag == 10)
		write(1, "Error: Code may be overlapped (check defines)\n", 46);
}

void	print_usage(t_corewar **corewar, int flag)
{
	print_usage_2(flag);
	gc_free();
	if ((*corewar)->all_champ)
		free_champ(corewar);
	if ((*corewar)->arena)
		free((*corewar)->arena);
	if ((*corewar)->all_carr)
		free_carriages(corewar);
	free(*corewar);
	exit(0);
}

void	error(void)
{
	write(1, "Crash\n", 6);
	exit(0);
}

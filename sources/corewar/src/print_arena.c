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

static void		hex_helper(int byte)
{
	char	print;

	if (byte >= 0 && byte <= 9)
		print = '0' + byte;
	else
		print = 'a' + byte - 10;
	write(1, &print, 1);
}

void			hexer_2(unsigned char byte_num)
{
	int		num;
	int		byte;

	num = (int)byte_num;
	byte = num / 16;
	hex_helper(byte);
	byte = num % 16;
	hex_helper(byte);
	write(1, " ", 1);
}

void			hexer_1(int str_num)
{
	int		byte_1;
	int		byte_2;
	int		byte_3;
	int		byte_4;

	write(1, "0x", 2);
	byte_4 = str_num % 16;
	str_num /= 16;
	byte_3 = str_num % 16;
	str_num /= 16;
	byte_2 = str_num % 16;
	str_num /= 16;
	byte_1 = str_num % 16;
	hex_helper(byte_1);
	hex_helper(byte_2);
	hex_helper(byte_3);
	hex_helper(byte_4);
	write(1, " : ", 3);
}

void			print_arena(t_corewar **corewar)
{
	int		str_num;
	int		byte_num;

	str_num = 0;
	while (str_num < MEM_SIZE)
	{
		byte_num = 0;
		hexer_1(str_num);
		while (byte_num < (*corewar)->flags.print_style)
		{
			hexer_2((*corewar)->arena[str_num + byte_num]);
			byte_num++;
		}
		write(1, "\n", 1);
		str_num += (*corewar)->flags.print_style;
	}
}

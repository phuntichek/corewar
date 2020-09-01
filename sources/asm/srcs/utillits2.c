/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillits2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by coconroy          #+#    #+#             */
/*   Updated: 2020/06/22 23:05:22 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	valid_end_line(t_parce *pr, int i)
{
	i++;
	while (ft_space(pr->line[i]))
		i++;
	if (pr->line[i] && pr->line[i] != '#')
		ft_error_pos("ERROR: unexpected symbol", pr->row, *pr->i);
}

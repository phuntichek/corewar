/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:38:32 by coconroy          #+#    #+#             */
/*   Updated: 2020/06/25 12:21:34 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_skip_space(t_parce *pr)
{
	while (ft_space(pr->line[*pr->i]))
		(*pr->i)++;
}

void				skip_comment(t_parce *pr)
{
	while (pr->line[*pr->i])
		(*pr->i)++;
}

void				skip_separator(t_parce *pr)
{
	int		i;

	i = *pr->i + 1;
	while (ft_space(pr->line[i]))
		i++;
	if (pr->line[i] != '\0')
		(*pr->i)++;
}

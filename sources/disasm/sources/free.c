/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschmele <fmelda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:29:11 by rschmele          #+#    #+#             */
/*   Updated: 2019/04/12 16:28:42 by rschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			ft_free(t_com *head)
{
	t_com		*cpy;
	t_com		*temp;

	cpy = head;
	while (cpy)
	{
		temp = cpy;
		cpy = cpy->next;
		free(temp->name);
		free(temp->arg);
		free(temp->t_arg);
		free(temp);
		temp = NULL;
	}
}

void			free_all(t_dasm *dasm)
{
	while (dasm->com)
	{
		free(dasm->com->arg);
		free(dasm->com->name);
		free(dasm->com->t_arg);
		free(dasm->com);
		dasm->com = dasm->com->next;
	}
	free(dasm->com);
	dasm->com = NULL;
	free(dasm->code);
	free(dasm->comment);
	free(dasm->file_name);
	ft_free(dasm->head);
	free(dasm->name);
	free(dasm);
}

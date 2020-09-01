/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:22:44 by ijate-bl          #+#    #+#             */
/*   Updated: 2020/03/09 23:22:45 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	gc_free(void)
{
	t_gc	*current;

	current = g_memory;
	while (current != NULL)
	{
		g_memory = g_memory->next;
		current->next = NULL;
		free(current->memory);
		current->memory = NULL;
		free(current);
		current = g_memory;
	}
}

void	**gc_malloc(size_t bytes)
{
	t_gc	*alloc_memory;

	alloc_memory = NULL;
	if (!(alloc_memory = (t_gc*)malloc(sizeof(t_gc))))
		error();
	if (!(alloc_memory->memory = (void*)malloc(bytes)))
		error();
	if (g_memory == NULL)
	{
		g_memory = alloc_memory;
		g_memory->next = NULL;
	}
	else
	{
		alloc_memory->next = g_memory;
		g_memory = alloc_memory;
	}
	return (&(alloc_memory->memory));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstoneha <jstoneha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:49:14 by jstoneha          #+#    #+#             */
/*   Updated: 2019/06/21 12:30:53 by jstoneha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strindex(const char *str, int c)
{
	int index;

	index = 0;
	if (!str)
		return (-2);
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return (index);
		index++;
	}
	return (-1);
}

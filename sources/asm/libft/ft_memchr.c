/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:23:21 by coconroy          #+#    #+#             */
/*   Updated: 2018/12/16 15:00:59 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*ps;
	size_t		i;
	char		x;

	i = 0;
	ps = (char *)s;
	x = (char)c;
	while (i < n)
	{
		if (ps[i] == x)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

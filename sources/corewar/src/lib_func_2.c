/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:10:10 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/09/29 22:48:04 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static char	*ft_put_str(char *str, int i, int s, int n)
{
	long	t;

	if (!str)
		return (str);
	str[i + s] = '\0';
	if (s && (n != 0))
		str[0] = '-';
	else if (n == 0)
		str[0] = 48;
	else
		i--;
	t = n;
	if (n < 0)
		t *= -1;
	while (t > 0)
	{
		str[i--] = (t % 10 + 48);
		t /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		s;
	long	t;

	str = NULL;
	i = 0;
	s = 0;
	t = n;
	if (t <= 0 && ++s)
		t *= -1;
	while (t > 0 && ++i)
		t /= 10;
	str = (char *)malloc(sizeof(char) * (i + s + 1));
	if (!str)
		return (NULL);
	str = ft_put_str(str, i, s, n);
	return (str);
}

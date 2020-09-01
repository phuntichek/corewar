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
#include <limits.h>

int			ft_atoi(const char *str)
{
	long	res;
	int		s;

	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	s = (*str == '-') ? -1 : 1;
	s = ((*str == '+') || (*str >= '0' && *str <= '9')) ? 1 : -1;
	str += ((*str == '+') || (*str == '-')) ? 1 : 0;
	while (*str >= '0' && *str <= '9')
	{
		if (((res > 922337203685477580) || (res == 922337203685477580 &&
						(*str > '7'))) && s == 1)
			return (-1);
		if (((res > 922337203685477580) || (res == 922337203685477580 &&
						(*str > '8'))) && s == -1)
			return (-1);
		res = res * 10 + (*str - 48);
		str++;
	}
	if (*str != '\0' || (s > 0 && (long)(res * s) > (long)(INT_MAX)) ||\
			(s < 0 && (long)(res * s) < (long)(INT_MIN)))
		return (-1);
	return ((int)res * s);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
		i++;
	if ((str1[i] == '\0') && (str2[i] == '\0'))
		return (0);
	return (str1[i] - str2[i]);
}

size_t		ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int			ft_numlen(size_t n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

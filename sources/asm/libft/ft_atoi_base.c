/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by coconroy          #+#    #+#             */
/*   Updated: 2020/06/23 00:19:27 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long			ft_atoi_base(char *str, int base)
{
	int					i;
	unsigned long		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * base + str[i] - 48;
		i++;
	}
	return (num);
}

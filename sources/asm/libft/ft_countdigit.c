/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:33:22 by coconroy          #+#    #+#             */
/*   Updated: 2020/02/01 11:45:51 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigit(long long dig)
{
	int num;
	int neg;

	num = 1;
	neg = 1;
	if (dig < 0)
	{
		neg = -1 * neg;
		dig = -1 * dig;
	}
	while (dig > 9)
	{
		dig = dig / 10;
		num++;
	}
	return (num);
}

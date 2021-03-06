/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coconroy <coconroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:18:16 by coconroy          #+#    #+#             */
/*   Updated: 2019/07/16 20:17:47 by coconroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_max_u(uintmax_t n)
{
	if (n > 9)
		ft_putnbr_max(n / 10, 0);
	ft_putchar(n % 10 + 48);
}

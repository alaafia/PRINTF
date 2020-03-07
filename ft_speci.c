/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:20:09 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 20:28:53 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_neg(t_flags t, long long n, int *len)
{
	if ((t.num_is_neg == 1 && t.ispres == 1 && t.lenpres == 0)
	|| (t.num_is_neg == 1 && t.ispres == 0 && t.flag_zero == 0)
	|| (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero == 0 && t.width == 0
	&& t.lenpres <= ft_numlen(n, t) && t.num_is_neg == 1))
		ft_putchar('-');
	ft_putnbr(n, t);
	if (t.num_is_neg == 1 && t.width <= ft_numlen(n, t))
		*len = *len + t.num_is_neg;
}

void				ft_putxx(long long nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
	{
		ft_putxx(n / 16);
		ft_swit((n % 16));
	}
	else
	{
		ft_swit(n);
	}
}

int				ft_hex(long long nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
	{
		ft_hex(n / 16);
		ft_switchx((n % 16));
	}
	else
	{
		ft_switchx(n);
	}
	return (0);
}

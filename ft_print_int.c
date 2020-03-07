/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:41:24 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 20:25:24 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int					ft_prin_integ(t_flags t, va_list str)
{
	long long			n;
	int					len;
	int					i;

	len = 0;
	i = 0;
	if (t.speci == 'd' || t.speci == 'i')
	{
		n = (long long)va_arg(str, int);
		if (n < 0)
			t.num_is_neg = 1;
		ft_zero(&t, n, &len);
		i = ft_without_flags(t, &len, n);
		ft_pres_minus(t, &len, n, &i);
		ft_pres_only(t, &len, n, &i);
		ft_pres_zero(t, &len, n, &i);
		ft_print_flag(t, &len, n, i);
	}
	return (len);
}

int					ft_prin_hex(t_flags t, va_list str)
{
	long long			n;
	int					len;
	int					i;

	len = 0;
	i = 0;
	if (t.speci == 'x')
	{
		n = (long long)va_arg(str, long);
		ft_zero(&t, n, &len);
		t.num_is_neg = 0;
		i = ft_without_flags(t, &len, n);
		ft_pres_minus(t, &len, n, &i);
		ft_pres_only(t, &len, n, &i);
		ft_pres_zero(t, &len, n, &i);
		ft_print_flag(t, &len, n, i);
	}
	return (len);
}

int					ft_prin_hexx(t_flags t, va_list str)
{
	long long			n;
	int					len;
	int					i;

	len = 0;
	i = 0;
	if (t.speci == 'X')
	{
		n = (long long)va_arg(str, long);
		ft_zero(&t, n, &len);
		t.num_is_neg = 0;
		i = ft_without_flags(t, &len, n);
		ft_pres_minus(t, &len, n, &i);
		ft_pres_only(t, &len, n, &i);
		ft_pres_zero(t, &len, n, &i);
		ft_print_flag(t, &len, n, i);
	}
	return (len);
}
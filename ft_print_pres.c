/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:42:57 by alaafia           #+#    #+#             */
/*   Updated: 2020/03/01 18:23:02 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_flag_pres(t_flags t, int len)
{
	if (t.ispres != 0)
	{
		if (t.lenpres > len)
		{
			if (t.num_is_neg == 1)
				ft_putchar('-');
			ft_printflag(t.lenpres - len, '0');
			if (!(t.lenpres < t.width))
				return (t.lenpres - t.width);
		}
		else
		{
			if (t.speci == 'u' && len > t.width)
				return (len - t.width);
			if (t.lenpres >= t.width)
				return (len);
		}
	}
	return (0);
}

void					ft_pres_len(t_flags t, int *len, long long n, int l)
{
	if (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero == 0 && t.width == 0)
		*len = *len + t.lenpres - 2 - t.is_etoile - t.is_etoile_pres - t.ispres;
	if (t.lenpres != 0 && t.flag_minus == 0 && t.width != 0)
	{
		if (t.width <= t.lenpres)
			*len = *len + t.width +  ft_flag_pres(t, l) - 2 - t.ispres - t.flag_zero
			- t.is_etoile - t.is_etoile_pres + t.num_is_neg - t.is_pres_zero;
		if (t.width > t.lenpres)
			*len = *len + t.width + ft_flag_pres(t, l) - 2 - t.ispres
			- t.is_etoile - t.is_etoile_pres - t.is_pres_zero - t.flag_zero;
	}
	if (t.is_etoile == 0)
		*len = *len - ft_numlen(t.width, t);
	if (t.is_etoile_pres == 0)
		*len = *len - ft_numlen(t.lenpres, t);
	if (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero != 0 && t.width == 0)
	{
		*len = *len - t.flag_zero - 2 - t.ispres + t.num_is_neg
		- t.is_etoile_pres - t.is_pres_zero - t.num_is_neg;
		if (t.lenpres >= ft_numlen(n, t))
			*len = *len + t.lenpres;
		else
			*len = *len + ft_numlen(n, t);
	}
}

void					ft_pres_only_help(t_flags t, long long n)
{
	int				l;

	l = ft_numlen(n, t);
	if (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero == 0 && t.width == 0)
	{
		if (t.lenpres > l)
		{
			if (t.num_is_neg == 1)
				ft_putchar('-');
			ft_printflag(t.lenpres - l, '0');
			ft_putnbr(n, t);
		}
	}
	if (t.lenpres != 0 && t.flag_minus == 0 && t.width != 0)
	{
		if (t.num_is_neg == 1 && t.lenpres <= ft_numlen(n, t))
			ft_putchar('-');
		ft_putnbr(n, t);
	}
}

void					ft_pres_only(t_flags t, int *len, long long n, int *i)
{
	int				l;

	l = ft_numlen(n, t);
	if (t.num_is_neg == 0 && t.width == 0 && t.ispres == 1)
		*len = *len - 1;
	if (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero == 0 && t.width == 0)
	{
		if (t.lenpres > l)
		{
			ft_pres_only_help(t, n);
			ft_pres_len(t, len, n, l);
		}
		else
		{
			ft_print_neg(t, n, len);
			*len = *len + l - ft_numlen(t.lenpres, t) - 2 - t.ispres - t.num_is_neg;
		}
	}
	if (t.lenpres != 0 && t.flag_minus == 0 && t.width != 0)
	{
		if (t.lenpres >= l)
			ft_printflag(t.width - t.lenpres - t.num_is_neg, ' ');
		else
			ft_printflag(t.width - l - t.num_is_neg, ' ');
		ft_pres_len(t, len, n, l);
		ft_pres_only_help(t, n);
		*i = 1;
	}
}

void					ft_pres_minus_len(t_flags t, int *len, long long n)
{
	int					l;

	l = t.width - t.lenpres;
	if (l <= 0 && t.lenpres != 0)
		l = 0;
	if (t.lenpres == 0)
		l = t.width;
	if (t.lenpres < ft_numlen(n, t))
		l = t.width - ft_numlen(n, t);
	if (t.ispres == 1 && t.lenpres != 0 && t.flag_minus != 0)
	{
		*len = *len + t.width + ft_flag_pres(t, ft_numlen(n, t)) - t.flag_zero
		- t.flag_minus - 2 - t.ispres - t.is_etoile - t.is_etoile_pres
		- t.is_pres_zero;
		if (t.num_is_neg == 1 && t.lenpres >= t.width && t.width >= ft_numlen(n, t))
			*len = *len + 1;
		if (t.is_etoile == 0)
			*len = *len - ft_numlen(t.width, t);
		if (t.is_etoile_pres == 0)
			*len = *len - ft_numlen(t.lenpres, t);
	}
}

void					ft_pres_minus(t_flags t, int *len, long long n, int *i)
{
	int					l;

	l = t.width - t.lenpres;
	if (l <= 0 && t.lenpres != 0)
		l = 0;
	if (t.lenpres < ft_numlen(n, t))
		l = t.width - ft_numlen(n, t);
	if (t.ispres == 1 && t.lenpres != 0 && t.flag_minus != 0)
	{
		ft_pres_minus_len(t, len, n);
		ft_print_neg(t, n, len);
		ft_printflag(l - t.num_is_neg, ' ');
		*i = 1;
	}
	if (t.lenpres != 0 && t.flag_minus == 0 && t.flag_zero != 0 && t.width == 0)
	{
		if (t.num_is_neg == 1)
			ft_putchar('-');
		ft_printflag(t.lenpres - ft_numlen(n, t), '0');
		ft_putnbr(n, t);
		ft_pres_len(t, len, n, l);
	}
}

void				ft_pres_zero(t_flags t, int *len, long long n, int *i)
{
	int					l;

	if (i == 0)
	{
		l = t.width - t.lenpres;
		if (l <= 0 && t.lenpres != 0)
			l = 0;
		if (t.lenpres == 0)
			l = t.width - ft_numlen(n, t);
		if (t.ispres == 1 && t.flag_zero != 0)
		{
			ft_printflag(l, ' ');
			*len = *len + l + ft_flag_pres(t, ft_numlen(n, t)) - 2 -
			ft_numlen(t.lenpres, t) - t.flag_zero - t.ispres - t.is_pres_zero
			- t.is_etoile - t.is_etoile_pres;
			if (t.is_pres_zero != 0 && t.lenpres == 0 && t.width == 0)
				*len = *len + 3;
			if (t.is_etoile == 0)
				*len = *len - ft_numlen(t.width, t);
			if (t.num_is_zero == 0)
				ft_putnbr(n, t);
			*i = 1;
		}
	}
}

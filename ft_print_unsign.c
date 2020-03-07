/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:26:10 by alaafia           #+#    #+#             */
/*   Updated: 2020/03/01 21:13:24 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_without_flags(t_flags t, int *len, long long n)
{
	if ((t.lenpres == 0 && t.flag_minus == 0 && t.flag_zero == 0 &&
	t.width != 0) || (t.lenpres == 0 && t.flag_minus == 0 && t.flag_zero != 0 &&
	t.width != 0 && t.ispres == 1))
	{
		if (t.width > ft_numlen(n, t))
		{
			ft_printflag(t.width - ft_numlen(n, t) - t.num_is_neg, ' ');
			*len = *len + t.width;
		}
		else
			*len = *len + ft_numlen(n, t);
		*len = *len - t.is_etoile - t.is_pres_zero
		- t.is_etoile_pres - t.ispres - 2 - t.flag_zero;
		if (t.is_etoile == 0)
			*len = *len - ft_numlen(t.width, t);
		ft_print_neg(t, n, len);
		return (1);
	}
	return (0);
}

void				ft_print_flag(t_flags t, int *len, long long n, int i)
{
	if (i == 0)
	{
		if (t.ispres == 1 && t.flag_minus == 0
		&& t.flag_zero != 0 && t.lenpres == 0)
		{
			ft_pres_minus(t, len, n, &i);
			*len = *len - t.flag_zero - t.is_etoile_pres - t.is_pres_zero;
		}
		if (t.lenpres == 0 && t.flag_minus == 0 &&
		t.flag_zero == 0 && t.width == 0)
			*len = *len + ft_numlen(n, t) - 2 - t.ispres;
		if (t.ispres == 0 && t.flag_minus == 0 && t.flag_zero != 0)
			*len = *len + ft_flag_zero(t, ft_numlen(n, t)) -
			t.flag_zero - 2 - 1;
		if (t.lenpres == 0 && t.num_is_zero == 0)
			ft_print_neg(t, n, len);
		if (t.lenpres == 0 && t.flag_minus != 0 && t.flag_zero == 0)
			*len = *len + ft_flag_minus(t, ft_numlen(n, t)) - t.ispres -
			t.flag_minus - 2 - ft_numlen(t.lenpres, t) - 1;
		if (t.lenpres == 0 && t.flag_minus != 0 && t.flag_zero != 0)
			*len = *len + ft_flag_minus(t, ft_numlen(n, t))
			- (t.flag_minus + t.flag_zero) - 2 - 1;
		if (t.is_etoile == 0)
			*len = *len - ft_numlen(t.width, t);
	}
}

void				ft_zero_help(t_flags *t, int *len)
{
	if (t->ispres == 0 || (t->ispres == 1
	&& t->lenpres <= t->width))
	{
		if (t->width != 0)
			t->width--;
		if (t->ispres == 1 && t->lenpres <= t->width)
			*len = *len + 1;
	}
	if (t->ispres == 1)
	{
		if (t->lenpres != 0)
		{
			t->lenpres--;
			if (t->lenpres == t->width && t->flag_minus != 0)
				*len = *len + 1;
			if (t->lenpres < t->width && t->flag_minus == 0)
				*len = *len - 1;
			if (t->lenpres >= t->width && t->flag_minus == 0)
				*len = *len + 1;
			if (t->lenpres > t->width && t->flag_minus != 0)
				*len = *len + 1;
		}
	}
}

void				ft_zero(t_flags *t, long long n, int *len)
{
	if (n == 0)
	{
		ft_zero_help(t, len);
		if (t->ispres == 1)
		{
			if (t->lenpres == 0)
			{
				t->lenpres = n;
				t->num_is_zero = 1;
				if (t->flag_minus != 0 || t->flag_zero != 0)
				{
					t->width++;
				}
			}
		}
	}
}

int					ft_prin_unsigned(t_flags t, va_list str)
{
	long long			n;
	int					len;
	int					i;

	len = 0;
	i = 0;
	if (t.speci == 'u')
	{
		n = (long long)va_arg(str, long);
		ft_zero(&t, n, &len);
		t.num_is_neg = 0;
		i = ft_without_flags(t, &len, n);
		ft_pres_minus(t, &len, n, &i);
		ft_pres_only(t, &len, n, &i);
		ft_pres_zero(t, &len, n, &i);
		ft_print_flag(t, &len, n, i);
		len += t.negative;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_outils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:16:48 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 19:09:34 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_print_str_without_pres(t_flags t, char *s, int *len)
{
	int			l;
	int			j;

	l = ft_strlen(s);
	j = 0;
	if (t.ispres == 0 && t.flag_zero == 0 && t.width <= l)
	{
		ft_putstr(s);
		if (t.width != 0)
			*len = *len - ft_numlen(t.width, t);
		*len = *len + l - 2 - t.ispres - t.flag_minus - ft_numlen(t.lenpres, t);
	}
	if (t.ispres == 0 && t.flag_minus == 0 &&
	t.flag_zero == 0 && t.width > l)
	{
		ft_printflag(t.width - l, ' ');
		while (j < l && s[j])
			ft_putchar(s[j++]);
		*len = *len + t.width - ft_numlen(t.width, t) - 2 - t.ispres;
	}
}

void					ft_print_str_minus(t_flags t, char *s, int *len)
{
	int			l;
	int			j;

	l = ft_strlen(s);
	j = 0;
	if (t.ispres == 0 && t.flag_minus != 0 &&
		t.flag_zero == 0 && t.width > l)
	{
		while (j < l && s[j])
			ft_putchar(s[j++]);
		ft_printflag(t.width - l, ' ');
		*len = t.width - ft_numlen(t.width, t) - 2 - t.ispres - t.flag_minus;
		if (t.is_etoile == 1)
			*len = *len + 1;
	}
}

void					ft_print_str_pres_only(t_flags t, char *s, int *len)
{
	int			l;
	int			j;

	l = ft_strlen(s);
	j = 0;
	if (t.ispres != 0 && t.flag_minus == 0 &&
		t.flag_zero == 0 && t.width >= t.lenpres)
	{
		if (t.lenpres < l)
			ft_printflag(t.width - t.lenpres, ' ');
		else
			ft_printflag(t.width - l, ' ');
		while (j < t.lenpres && s[j])
			ft_putchar(s[j++]);
		*len = t.width - ft_numlen(t.width, t) - 2 -
		t.ispres - ft_numlen(t.lenpres, t);
	}
}

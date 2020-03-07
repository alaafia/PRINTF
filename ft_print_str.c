/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:15:04 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 19:10:36 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_str_pres(t_flags t, char *s, int *len, int j)
{
	if (t.ispres != 0 && t.flag_minus == 0 &&
		t.flag_zero == 0 && t.width < t.lenpres)
	{
		if (t.width > ft_strlen(s))
		{
			ft_printflag(t.width - ft_strlen(s), ' ');
			*len = t.width - ft_numlen(t.lenpres, t) - 2 -
				t.ispres - ft_numlen(t.width, t);
		}
		if (t.width <= ft_strlen(s))
		{
			if (t.lenpres > ft_strlen(s))
			{
				*len = ft_strlen(s) - ft_numlen(t.lenpres, t) - 2 -
				t.ispres - ft_numlen(t.width, t);
			}
			else
			{
				*len = t.lenpres - ft_numlen(t.lenpres, t) - 2 -
				t.ispres - ft_numlen(t.width, t);
			}
		}
		while (j < t.lenpres && s[j])
			ft_putchar(s[j++]);
	}
}

void				ft_print_str_help(t_flags t, char *s, int *len)
{
	int			l;

	l = ft_strlen(s);
	if (t.width > t.lenpres)
	{
		ft_printflag(t.width - t.lenpres, ' ');
		*len = t.width - ft_numlen(t.width, t) - 2 -
		t.ispres - t.flag_minus - ft_numlen(t.lenpres, t);
	}
	else
		*len = t.lenpres - ft_numlen(t.lenpres, t) -
		2 - t.flag_minus - t.ispres - ft_numlen(t.width, t);
	if (t.is_etoile == 1)
		*len = *len + ft_numlen(t.width, t) - t.is_etoile;
	if (t.is_etoile_pres == 1)
		*len = *len + ft_numlen(t.lenpres, t) - t.is_etoile_pres;
}

void				ft_print_str_minus_pres(t_flags t, char *s, int *len)
{
	int			l;
	int			j;

	l = ft_strlen(s);
	j = 0;
	while (j < t.lenpres && s[j])
		ft_putchar(s[j++]);
	if (t.lenpres < l)
		ft_print_str_help(t, s, len);
	else
	{
		ft_printflag(t.width - l, ' ');
		if (t.width < t.lenpres)
		{
			*len = t.width - ft_numlen(t.width, t) - 2 -
			t.ispres - t.flag_minus - ft_numlen(t.lenpres, t);
		}
		else
		{
			*len = t.width - ft_numlen(t.width, t) - 2 -
			t.ispres - t.flag_minus - ft_numlen(t.lenpres, t);
		}
	}
}

void				ft_init_var(int *l, int *j, int *len, char **s)
{
	*s = NULL;
	*l = 0;
	*j = 0;
	*len = 0;
}

int					ft_print_str(t_flags t, va_list str)
{
	int			l;
	int			j;
	int			len;
	char		*s;

	ft_init_var(&l, &j, &len, &s);
	if (t.speci == 's')
	{
		s = (char *)va_arg(str, char *);
		l = ft_strlen(s);
		if (t.negative == -1)
			t.lenpres = l;
		ft_print_str_without_pres(t, s, &len);
		ft_print_str_minus(t, s, &len);
		ft_print_str_pres_only(t, s, &len);
		ft_print_str_pres(t, s, &len, j);
		if (t.ispres != 0 && t.flag_minus != 0 &&
		t.flag_zero == 0)
		{
			ft_print_str_minus_pres(t, s, &len);
			if (t.is_etoile == 1)
				len++;
		}
	}
	return (len);
}

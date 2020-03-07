/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:47:12 by alaafia           #+#    #+#             */
/*   Updated: 2020/03/01 18:04:15 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_perc(char *s, int *i)
{
	if (s[*i] == '%')
	{
		ft_putchar('%');
		*i = *i + 1;
		return (0);
	}
	return (1);
}

int				ft_space(char *s, int *i)
{
	int			nb;

	nb = 0;
	while (s[*i] == ' ')
	{
		*i = *i + 1;
		nb++;
	}
	return (nb);
}

int					ft_print_pointer(t_flags t, va_list str)
{
	int					len;

	len = 0;
	if (t.speci == 'p' && t.lenpres == 0 && t.flag_zero == 0)
	{
		if (t.flag_minus == 0 && t.width > 14)
		{
			ft_printflag(t.width - 14, ' ');
			len = t.width - 2 - t.ispres - ft_numlen(t.width, t);
		}
		if (t.width <= 14)
			len = 12 - t.ispres - ft_numlen(t.width, t) - t.flag_minus;
		ft_putstr("0x");
		ft_hex((long int)va_arg(str, long int));
		if (t.flag_minus != 0 && t.width > 14)
		{
			ft_printflag(t.width - 14, ' ');
			len = t.width - 2 - t.ispres - ft_numlen(t.width, t) - t.flag_minus;
		}
		if (t.is_etoile == 1)
			len += ft_numlen(t.width, t) - t.is_etoile;
	}
	return (len);
}

int					ft_printf(char *s, ...)
{
	int				i;
	int				count;
	va_list			str;
	t_flags			flg;

	if (s == NULL)
		return (0);
	va_start(str, s);
	i = 0;
	count = 0;
	ft_init(&flg);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i++]);
		else
		{
			i++;
			if (ft_perc(s, &i))
	   		{
				count = count - ft_space(s, &i);
				i += ft_stock(s + i, &flg, str);
		   		// printf("num is neg ; %d\nflag_zero : %d \nflag_minus %d\nwidth %d\nis_etoile %d\nispres %d\nisetoile_pres%d\nenpres %d\nis_pres_zero %d\nspeci %c\n",flg.num_is_neg,flg.flag_zero,flg.flag_minus,flg.width,flg.is_etoile,flg.ispres,flg.is_etoile_pres,flg.lenpres,flg.is_pres_zero,flg.speci);
				count += ft_print_str(flg, str);
				count += ft_prin_integ(flg, str);
				count += ft_print_char(flg, str);
				count += ft_prin_unsigned(flg, str);
				count += ft_print_pointer(flg, str);
				count += ft_prin_hex(flg, str);
				count += ft_prin_hexx(flg, str);
			}
		}
	}
	va_end(str);
	return (count + i);
}

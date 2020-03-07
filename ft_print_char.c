/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:44:56 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 19:09:18 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_char(t_flags t, va_list str)
{
	char		c;
	int			l;

	l = 0;
	if (t.speci == 'c')
	{
		c = (char)(va_arg(str, int));
		if (t.flag_minus == 0 && t.width != 0)
		{
			ft_printflag(t.width - 1, ' ');
			if (t.is_etoile == 0)
				l -= ft_numlen(t.width, t) - 1;
			l += t.width - 2;
		}
		ft_putchar(c);
		if (t.flag_minus != 0)
			l += ft_flag_minus(t, 1) - 2;
		if (t.is_etoile == 0 && t.flag_minus != 0)
			l -= ft_numlen(t.width, t);
		if (t.width == 0 && t.is_etoile == 1)
			l--;
		return (l - 1 - t.ispres);
	}
	return (0);
}
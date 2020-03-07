/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:51:19 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/26 17:54:35 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printflag(int wid, char c)
{
	while (wid > 0)
	{
		ft_putchar(c);
		wid--;
	}
}

int					ft_flag_zero(t_flags t, int len)
{
	if (t.flag_zero != 0)
	{
		if (t.flag_minus == 0)
		{
			if (t.width > len)
			{
				if (t.num_is_neg == 1)
				{
					ft_putchar('-');
					t.width--;
				}
				ft_printflag(t.width - len, '0');
				return (t.width + t.num_is_neg);
			}
			else
			{
				if (t.num_is_neg == 1)
					ft_putchar('-');
				return (len);
			}
		}
	}
	return (0);
}

int					ft_flag_minus(t_flags t, int len)
{
	if (t.flag_minus != 0)
	{
		if (t.width > len)
		{
			ft_printflag(t.width - len - t.num_is_neg, ' ');
			return (t.width);
		}
		else
			return (len);
	}
	return (0);
}

int					ft_etoile(int condition, va_list str, int len)
{
	if (condition != 0)
		return ((int)va_arg(str, int));
	else
	{
		return (len);
	}
}

void				ft_flag_etoile(char *s, int *arg, int *i)
{
	if (s[*i] == '*')
	{
		*arg = 1;
		*i = *i + 1;
	}
}

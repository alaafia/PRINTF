/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:21:56 by alaafia           #+#    #+#             */
/*   Updated: 2020/03/01 18:34:43 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_hex_len(long long n)
{
	int						j;

	j = 0;
	while (n)
	{
		j++;
		n = n / 16;
	}
	return (j);
}

int					ft_numlen(long n, t_flags t)
{
	int			i;

	if (t.speci == 'x' || t.speci == 'X')
		{
			return (ft_hex_len(n));
		}
	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int					ft_look(char *s, char c, int *i)
{
	int			n;

	n = 0;
	while (s[*i] == c)
	{
		n++;
		*i = *i + 1;
	}
	return (n);
}

int					ft_strlen(const char *str)
{
	int			i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

int					ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

int					ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

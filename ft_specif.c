/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:21:09 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 19:00:16 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int			ft_putnbr(long long nb, t_flags t)
{
	if (t.speci	== 'x' || t.speci == 'X')
	{
		if (t.speci	== 'x')
			return (ft_hex(nb));
		else
			ft_putxx(nb);
	}
	else
	{
		if (nb < 0)
		nb = nb * -1;
		if (nb > 9)
		{
			ft_putnbr(nb / 10, t);
			ft_putchar((nb % 10) + 48);
		}
		else
			ft_putchar(nb + 48);
	}
	return (0);
}

void			ft_swit(int x)
{
	if (x > 9)
	{
		if (x == 10)
			ft_putchar('A');
		if (x == 11)
			ft_putchar('B');
		if (x == 12)
			ft_putchar('C');
		if (x == 13)
			ft_putchar('D');
		if (x == 14)
			ft_putchar('E');
		if (x == 15)
			ft_putchar('F');
	}
	else
		ft_putchar(x + 48);
}

void			ft_switchx(int x)
{
	if (x > 9)
	{
		if (x == 10)
			ft_putchar('a');
		if (x == 11)
			ft_putchar('b');
		if (x == 12)
			ft_putchar('c');
		if (x == 13)
			ft_putchar('d');
		if (x == 14)
			ft_putchar('e');
		if (x == 15)
			ft_putchar('f');
	}
	else
		ft_putchar(x + 48);
}

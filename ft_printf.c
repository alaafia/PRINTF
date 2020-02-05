/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 00:47:12 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/05 16:31:59 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void					ft_putchar(char c)
{
	write(1, &c, 1);
}

void					ft_putstr(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void					ft_putnbr(int nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else
		ft_putchar(n + 48);
}

void					ft_swit(int x)
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

void				ft_switchx(int x)
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

void				ft_putx(int nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
	{
		ft_putx(n / 16);
		ft_switchx((n % 16));
	}
	else
	{
		ft_switchx(n);
	}
}


void				ft_putxx(int nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
	{
		ft_putxx(n / 16);
		ft_swit((n % 16));
	}
	else
		ft_swit(n);
}

void				ft_hex(long long nb)
{
	long long				n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
	{
		ft_hex(n / 16);
		ft_switchx((n % 16));
	}
	else
		ft_switchx(n);
}

void				ft_printf(char *s, ...)
{
	int				i;
	va_list			str;

	va_start(str, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i++]);
		else
		{
			i++;
			if (s[i] == '%')
				ft_putchar('%');
			if (s[i] == 'd' || s[i] == 'i')
				ft_putnbr((int)va_arg(str, int));
			if (s[i] == 'u')
			{
				int n;
				if ((n = (int)va_arg(str, int)) >= 0)
					ft_putnbr(n);
				else
					ft_putnbr(0);
			}
			if (s[i] == 'x')
				ft_putx((int)va_arg(str, int));
			if (s[i] == 'X')
				ft_putxx((int)va_arg(str, int));
			if (s[i] == 'p')
			{
				ft_putstr("0x");
				ft_hex((long int)va_arg(str, long int));
			}
			if (s[i] == 'c')
				ft_putchar(va_arg(str, int));
			if (s[i] == 's')
				ft_putstr((char *)va_arg(str, char *));
			i++;
		}
	}
	va_end(str);
}

int main (void)
{
   int	a = 24;
   char		*t = "txt";
   
  printf("%p\n",t);
  ft_printf("%p\n",t);
ft_printf("test char : %c \nstring : %s\nunsigned int : %u\n hexadecimal num %X\n",'f',"okaay wait",1111,455578);
printf("test char : %c \nstring : %s\nunsigned int : %u\n hexadecimal num %X",'f',"okaay wait ",1111,455578);
}
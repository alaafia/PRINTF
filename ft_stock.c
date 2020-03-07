/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:11:17 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 18:48:12 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_init(t_flags *flg)
{
	flg->flag_minus = 0;
	flg->flag_zero = 0;
	flg->width = 0;
	flg->is_etoile = 0;
	flg->ispres = 0;
	flg->lenpres = 0;
	flg->is_etoile_pres = 0;
	flg->is_pres_zero = 0;
	flg->speci = '\0';
	flg->negative = 0;
	flg->num_is_zero = 0;
	flg->num_is_neg = 0;
}

int					ft_width(char *s, t_flags *flg, int *i, va_list str)
{
	while (ft_isdigit(s[*i]) && flg->is_etoile == 0)
	{
		flg->width = 10 * flg->width + s[*i] - '0';
		*i = *i + 1;
	}
	flg->width = ft_etoile(flg->is_etoile, str, flg->width);
	if (flg->width < 0)
	{
		flg->width = -1 * flg->width;
		flg->flag_minus += 1;
		flg->negative = 1;
	}
	return (flg->width);
}

int					ft_lenpres(char *s, t_flags *flg, int *i, va_list str)
{
	while (ft_isdigit(s[*i]) && flg->is_etoile_pres == 0)
	{
		flg->lenpres = 10 * flg->lenpres + s[*i] - '0';
		*i = *i + 1;
	}
	if (flg->is_etoile_pres == 1)
		flg->lenpres = ft_etoile(flg->is_etoile_pres, str, flg->lenpres);
	if (flg->lenpres < 0)
	{
		flg->lenpres = 0;
		flg->negative = -1;
	}
	return (flg->lenpres);
}

int					ft_stock(char *s, t_flags *flg, va_list str)
{
	int					i;

	i = 0;
	ft_init(flg);
	while (s[i] == '0' || s[i] == '-')
	{
		flg->flag_zero += ft_look(s, '0', &i);
		flg->flag_minus += ft_look(s, '-', &i);
	}
	ft_flag_etoile(s, &flg->is_etoile, &i);
	flg->width = ft_width(s, flg, &i, str);
	if (s[i] == '.')
	{
		flg->ispres = 1;
		i++;
	}
	ft_flag_etoile(s, &flg->is_etoile_pres, &i);
	flg->is_pres_zero = ft_look(s, '0', &i);
	flg->lenpres = ft_lenpres(s, flg, &i, str);
	if (ft_isalpha(s[i]) == 1)
		flg->speci = s[i++];
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:52:57 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/28 20:29:46 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//%[flags][width][.precision][length]specifier

typedef struct				s_flags
{
	int				negative;
	int				flag_zero;
	int				flag_minus;
	int				width;
	int				is_etoile;
	int				ispres;
	int				is_etoile_pres;
	int				is_pres_zero;
	int				is_pres_negative;
	int				lenpres;
	char			speci;
	int				num_is_zero;
	int				num_is_neg;
}							t_flags;
void						ft_putchar(char c);
void						ft_putstr(const char *s);
int							ft_putnbr(long long nb, t_flags t);
void						ft_swit(int x);
void						ft_switchx(int x);
void						ft_putxx(long long nb);
int							ft_hex(long long nb);
int							ft_isdigit(int arg);
void						ft_printflag(int wid, char c);
int							ft_stock(char *s, t_flags *flg, va_list str);
int							ft_isdigit(int arg);
int							ft_perc(char *s, int *i);
int							ft_numlen(long n, t_flags t);
int							ft_strlen(const char *str);
int							ft_isalpha(int c);
void						ft_init(t_flags *flg);
int							ft_look(char *s, char c, int *i);
int							ft_prin_num(t_flags t, va_list str);
int							ft_flag_zero(t_flags t, int len);
int							ft_flag_minus(t_flags t, int len);
void						ft_flag_etoile(char *s, int *arg, int *i);
int							ft_flag_pres(t_flags t, int len);
void						ft_pres_only(t_flags t, int *len,
							long long n, int *i);
void						ft_pres_minus(t_flags t, int *len,
							long long n, int *i);
void						ft_pres_zero(t_flags t, int *len,
							long long n, int *i);
int							ft_etoile(int condition, va_list str, int len);
int							ft_width(char *s, t_flags *flg, int *i,
							va_list str);
int							ft_lenpres(char *s, t_flags *flg, int *i,
							va_list str);

int							ft_without_flags(t_flags t, int *len, long long n);
void						ft_print_flag(t_flags t, int *len,
							long long n, int i);
int							ft_prin_integ(t_flags t, va_list str);

int							ft_flag_pres(t_flags t, int len);
int							ft_printf(char *s, ...);
int							ft_etoile(int condition, va_list str, int len);
int							ft_prin_unsigned(t_flags t, va_list str);
void						ft_zero_help(t_flags *t, int *len);
void						ft_zero(t_flags *t, long long n, int *len);
int							ft_print_char(t_flags t, va_list str);
int							ft_print_str(t_flags t, va_list str);
void						ft_init_var(int *l, int *j, int *len, char **s);
void						ft_print_str_minus_pres(t_flags t, char *s,
							int *len);
void						ft_print_str_pres(t_flags t, char *s, int *len,
							int j);
void						ft_print_str_help(t_flags t, char *s, int *len);
void						ft_print_str_pres_only(t_flags t, char *s,
							int *len);
void						ft_print_str_minus(t_flags t, char *s, int *len);
void						ft_print_str_without_pres(t_flags t, char *s,
							int *len);
int							ft_print_pointer(t_flags t, va_list str);
void						ft_print_neg(t_flags t, long long n, int *len);
int							ft_prin_hex(t_flags t, va_list str);
int							ft_prin_hexx(t_flags t, va_list str);

#endif

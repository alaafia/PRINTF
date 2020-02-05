/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:52:57 by alaafia           #+#    #+#             */
/*   Updated: 2020/02/05 21:43:21 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//%[flags][width][.precision]specifier

typedef struct s_prin
{
    char        flags;
    int         width;
    char        pres;
    char        specif;
}t_prin;

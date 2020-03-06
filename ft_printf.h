/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:57:33 by omercade          #+#    #+#             */
/*   Updated: 2020/03/05 17:56:52 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

#define TRUE 1
#define FALSE 0

typedef struct	s_format
{
	int			width;
	int			prc;
	int			zeros;
	int			jleft;
	int			total;
	int			i;
}				t_format;

t_format		char_writer(char *str, va_list vl, t_format li);
t_format		str_writer(char *str, va_list vl, t_format li);
t_format		ptr_writer(char *str, va_list vl, t_format li);
t_format		per_writer(char *str, va_list vl, t_format li);

t_format		dec_writer(char *str, va_list vl, t_format li);
t_format		int_writer(char *str, va_list vl, t_format li);
t_format		unsig_writer(char *str, va_list vl, t_format li);
t_format		hex_writer(char *str, va_list vl, t_format li);
t_format		unsighex_writer(char *str, va_list vl, t_format li);

void			ft_putstr(char *str);
t_format		dtoh(long n, t_format li);

#endif
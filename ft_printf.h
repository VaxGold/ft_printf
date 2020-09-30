/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:57:33 by omercade          #+#    #+#             */
/*   Updated: 2020/09/30 20:01:19 by omercade         ###   ########.fr       */
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

t_format		var_choice(char *str, va_list vl, t_format fmt);
t_format		flag_check(char *str, va_list vl, t_format fmt);
t_format		ft_init (t_format fmt);
int				ft_printf(char *str, ...);

t_format		char_writer(va_list vl, t_format fmt);
t_format		str_writer(va_list vl, t_format fmt);
t_format		ptr_writer(va_list vl, t_format fmt);
t_format		per_writer(t_format fmt);

t_format		dec_writer(va_list vl, t_format fmt);
t_format		int_writer(va_list vl, t_format fmt);
t_format		unsig_writer(va_list vl, t_format fmt);
t_format		hex_writer(va_list vl, t_format fmt);
t_format		unsighex_writer(va_list vl, t_format fmt);

int				ft_putstr(char *str);
t_format		ft_writewidth(int n, char cwidth, t_format fmt);
int				ft_itoa_base(int n, char *base, int mode);
int				ft_utoa(unsigned int n, char *base, int mode);

#endif
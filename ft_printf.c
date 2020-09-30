/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:19:14 by omercade          #+#    #+#             */
/*   Updated: 2020/09/30 20:01:17 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_format		var_choice(char *str, va_list vl, t_format fmt)
{
	fmt.i++;
	if (str[fmt.i] == 'c')
		fmt = char_writer(vl, fmt);
	else if (str[fmt.i] == 's')
		fmt = str_writer(vl, fmt);
	else if (str[fmt.i] == 'p')
		fmt = ptr_writer(vl, fmt);
	else if (str[fmt.i] == 'd')
		fmt = int_writer(vl, fmt);
	else if (str[fmt.i] == 'i')
		fmt = int_writer(vl, fmt);
	else if (str[fmt.i] == 'u')
		fmt = unsig_writer(vl, fmt);
	else if (str[fmt.i] == 'x')
		fmt = hex_writer(vl, fmt);
	else if (str[fmt.i] == 'X')
		fmt = unsighex_writer(vl, fmt);
	else if (str[fmt.i] == '%')
		fmt = per_writer(fmt);
	return (fmt);
}

t_format		flag_check(char *str, va_list vl, t_format fmt)
{
	int 		n;

	n = 1;
	while (str[fmt.i + n] && ft_strchr("-*01234456789", str[fmt.i + n]) > 0)
	{
		if (str[fmt.i + n] == '-')
			fmt.jleft = FALSE;
		else if (str[fmt.i + n] == '0' && n == 1)
			fmt.zeros = TRUE;
		else if (str[fmt.i + n] == '*')
			fmt.width = va_arg(vl, int);
		else if (str[fmt.i + n] >= '0' && str[fmt.i + n] <= '9')
			fmt.width = fmt.width * 10 + (str[fmt.i + n] - '0');
		n++;
	}
	if (str[fmt.i + n] == '.')
	{
		while (str[fmt.i + (++n)] >= '0' && str[fmt.i + n] <= '9')
			fmt.prc = fmt.prc * 10 + (str[fmt.i + n++] - '0');
		if (str[fmt.i + n] == '*')
			fmt.prc = va_arg(vl, int);
	}
	fmt.i = fmt.i + n - 1;
	fmt = var_choice(str, vl, fmt);
	return (fmt);
}

t_format		ft_init(t_format fmt)
{
	fmt.width = 0;
	fmt.prc = 0;
	fmt.zeros = FALSE;
	fmt.jleft = TRUE;
	return (fmt);
}

int				ft_printf(char *str, ...)
{
	t_format	fmt;
	va_list 	vl;
	int			total;

	ft_bzero(&fmt, sizeof(t_format));
	va_start(vl, str);
	while(str[fmt.i] != 0)
	{
		if(str[fmt.i] == '%')
			fmt = flag_check(str, vl, fmt);
		else
			fmt.total += write(1, &str[fmt.i], 1);
		fmt.i++;
		fmt = ft_init(fmt);
	}
	va_end(vl);
	total = fmt.total;
	return (total);
}

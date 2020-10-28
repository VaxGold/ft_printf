/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:56 by omercade          #+#    #+#             */
/*   Updated: 2020/10/28 19:51:57 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			int_writer(va_list vl, t_format fmt)
{
	int				i;
	int				nsp;
	long long int	n;
	char			*str;

	n = (long long int)va_arg(vl, int);
	str = (fmt.prc == 0 && n == 0) ?
		ft_strdup("") : ft_itoa_base(n, "0123456789");
	if (fmt.prc < 0 && fmt.zeros == '0')
		fmt.prc = (n < 0 && fmt.jleft == FALSE) ? fmt.width - 1 : fmt.width;
	nsp = ((int)ft_strlen(str) < fmt.prc) ?
		fmt.width - fmt.prc : fmt.width - ft_strlen(str);
	nsp -= (n < 0 && (int)ft_strlen(str) <= fmt.prc) ? 1 : 0;
	i = 0;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	if (n < 0)
		fmt.total += write(1, &str[i++], 1);
	while (fmt.prc-- > (int)ft_strlen(str) - (*str == '-'))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(&str[i]);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	free(str);
	return (fmt);
}

t_format			unsig_writer(va_list vl, t_format fmt)
{
	int				i;
	int				nsp;
	unsigned int    n;
	char			*str;

	n = va_arg(vl, unsigned int);
	str = (fmt.prc == 0 && n == 0) ?
		ft_strdup("") : ft_itoa_base(n, "0123456789");
	if (fmt.prc < 0 && fmt.zeros == '0')
		fmt.prc = (n < 0 && fmt.jleft == FALSE) ? fmt.width - 1 : fmt.width;
	nsp = ((int)ft_strlen(str) < fmt.prc) ?
		fmt.width - fmt.prc : fmt.width - ft_strlen(str);
	i = 0;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	while (fmt.prc-- > (int)ft_strlen(str))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(&str[i]);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	free(str);
	return (fmt);
}

t_format			hex_writer(va_list vl, t_format fmt)
{
	int				i;
	int				nsp;
	unsigned int    n;
	char			*str;

	n = va_arg(vl, int);
	str = (fmt.prc == 0 && n == 0) ?
		ft_strdup("") : ft_itoa_base(n, "0123456789abcdef");
	if (fmt.prc < 0 && fmt.zeros == '0')
		fmt.prc = (n < 0 && fmt.jleft == FALSE) ? fmt.width - 1 : fmt.width;
	nsp = ((int)ft_strlen(str) < fmt.prc) ?
		fmt.width - fmt.prc : fmt.width - ft_strlen(str);
	i = 0;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	while (fmt.prc-- > (int)ft_strlen(str))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(&str[i]);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	free(str);
	return (fmt);
}

t_format			unsighex_writer(va_list vl, t_format fmt)
{
	int				i;
	int				nsp;
	unsigned int    n;
	char			*str;

	n = va_arg(vl, int);
	str = (fmt.prc == 0 && n == 0) ?
		ft_strdup("") : ft_itoa_base(n, "0123456789ABCDEF");
	if (fmt.prc < 0 && fmt.zeros == '0')
		fmt.prc = (n < 0 && fmt.jleft == FALSE) ? fmt.width - 1 : fmt.width;
	nsp = ((int)ft_strlen(str) < fmt.prc) ?
		fmt.width - fmt.prc : fmt.width - ft_strlen(str);
	i = 0;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	while (fmt.prc-- > (int)ft_strlen(str))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(&str[i]);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	free(str);
	return (fmt);
}

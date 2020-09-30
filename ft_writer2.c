/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:56 by omercade          #+#    #+#             */
/*   Updated: 2020/09/30 20:01:13 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			int_writer(va_list vl, t_format fmt)
{
	int			i;
	long int	n;
	int			len;
	char		cwidth;

	n = (long)va_arg(vl, int);
	len = ((int)ft_strlen(ft_itoa(n)) < fmt.prc) ? fmt.prc : (int)ft_strlen(ft_itoa(n));
	i = 0;
	cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - (int)ft_strlen(ft_itoa(n)))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(ft_itoa(n));
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	return (fmt);
}

t_format			unsig_writer(va_list vl, t_format fmt)
{
	int             i;
	unsigned int    n;
	int             len;
	char            cwidth;

	n = va_arg(vl, unsigned int);
	len = (ft_utoa(n, "0123456789", 1) < fmt.prc) ? fmt.prc : ft_utoa(n, "0123456789", 1);
	i = 0;
	cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_utoa(n, "0123456789", 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_utoa(n, "0123456789", 0);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	return (fmt);
}

t_format			hex_writer(va_list vl, t_format fmt)
{
	int		i;
	int		n;
	int		len;
	char	*base;
	char	cwidth;
	
	base = ft_strdup("0123456789abcdef");
	n = va_arg(vl, int);
	len = (ft_itoa_base(n, base, 1) < fmt.prc) ? fmt.prc : ft_itoa_base(n, base, 1);
	i = 0;
	cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_itoa_base(n, base, 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_itoa_base(n, base, 0);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	return (fmt);
}

t_format			unsighex_writer(va_list vl, t_format fmt)
{
	int         i;
	int         n;
	int         len;
	char		*base;
	char		cwidth;

	base = ft_strdup("0123456789ABCDEF");
	n = va_arg(vl, int);
	len = (ft_itoa_base(n, base, 1) < fmt.prc) ? fmt.prc : ft_itoa_base(n, base, 1);
	i = 0;
	cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_itoa_base(n, base, 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_itoa_base(n, base, 0);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	return (fmt);
}
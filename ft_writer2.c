/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:56 by omercade          #+#    #+#             */
/*   Updated: 2020/10/27 19:45:09 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*t_format			int_writer(va_list vl, t_format fmt)
{
	int			i;
	long int	n;
	int			len;
	char		cwidth;
	char		*base;

	base = ft_strdup("0123456789");
	n = (long)va_arg(vl, int);
	len = (ft_itoa_base(n, base, 1) < fmt.prc) ? fmt.prc : ft_itoa_base(n, base, 1);
	i = 0;
	cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	if (n < 0)
		fmt.total += write(1, "-", 1);
	while (i++ < fmt.prc - ft_itoa_base(n, base, 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_itoa_base(n, base, 0);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	return (fmt);
}*/

t_format			int_writer(va_list vl, t_format fmt)
{
	int				i;
	long long int	n;
	int				len;
	char			*str;
	int				sign;

	n = (long long int)va_arg(vl, int);
	sign = (n < 0) ? 1 : 0;
	str = (n == 0 && fmt.prc == 0) ? ft_strdup("") : ft_itoa_base(n, "0123456789");
	len = ((int)ft_strlen(str) < fmt.prc) ? fmt.prc : ft_strlen(str);
	i = 0;
	if (sign > 0 && fmt.zeros == '0')
		fmt.total += write(1, "-", 1);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len + !ft_strlen(str), fmt.zeros, fmt);
	if (sign > 0 && fmt.zeros != '0')
		fmt.total += write(1, "-", 1);
	while (fmt.prc-- > (int)ft_strlen(str))
		fmt.total += write(1, "0", 1);
	while (str[i + sign] != 0)
		fmt.total += write(1, &str[sign + (i++)], 1);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, fmt.zeros, fmt);
	// free(str);
	return (fmt);
}

t_format			unsig_writer(va_list vl, t_format fmt)
{
	int             i;
	unsigned int    n;
	//int             len;

	n = va_arg(vl, unsigned int);
	//len = (ft_utoa(n, "0123456789", 1) < fmt.prc) ? fmt.prc : ft_utoa(n, "0123456789", 1);
	i = 0;
	/*cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_utoa(n, "0123456789", 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_utoa(n, "0123456789", 0);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);*/
	return (fmt);
}

t_format			hex_writer(va_list vl, t_format fmt)
{
	int		i;
	int		n;
	//int		len;
	char	*base;
	
	base = ft_strdup("0123456789abcdef");
	n = va_arg(vl, int);
	//len = (ft_itoa_base(n, base) < fmt.prc) ? fmt.prc : ft_itoa_base(n, base;
	i = 0;
	/*cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_itoa_base(n, base, 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_itoa_base(n, base, 0);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);*/
	return (fmt);
}

t_format			unsighex_writer(va_list vl, t_format fmt)
{
	int         i;
	int         n;
	//int         len;
	char		*base;

	base = ft_strdup("0123456789ABCDEF");
	n = va_arg(vl, int);
	//len = (ft_itoa_base(n, base) < fmt.prc) ? fmt.prc : ft_itoa_base(n, base);
	i = 0;
	/*cwidth = (fmt.zeros == TRUE) ? '0' : ' ';
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);
	while (i++ < fmt.prc - ft_itoa_base(n, base, 1))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_itoa_base(n, base, 0);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, cwidth, fmt);*/
	return (fmt);
}

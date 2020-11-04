/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:40 by omercade          #+#    #+#             */
/*   Updated: 2020/11/03 20:51:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			char_writer(va_list vl, t_format fmt)
{
	char	c;
	int		nsp;

	c = va_arg(vl, int);
	nsp = fmt.width - 1;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	fmt.total += write(1, &c, 1);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	return (fmt);
}

t_format			str_writer(va_list vl, t_format fmt)
{
	int		i;
	char	*str;
	int		len;

	str = va_arg(vl, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	i = (int)ft_strlen(str);
	len = (fmt.prc < i) ? fmt.prc : i;
	fmt.prc = (len > 0) ? len : fmt.prc;
	len = (len < 0) ? i : len;
	str = ft_substr(str, 0, len);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	fmt.total += ft_putstr(str);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	free(str);
	return (fmt);
}

t_format			ptr_writer(va_list vl, t_format fmt)
{
	void		*ptr;
	long int	nptr;
	int			i;
	int			nsp;
	char		*str;

	ptr = va_arg(vl, void *);
	nptr = (long)ptr;
	str = (fmt.prc == 0 && nptr == 0) ?
		ft_strdup("") : ft_itoa_base(nptr, "0123456789abcdef");
	if (fmt.prc < 0 && fmt.zeros == '0')
		fmt.prc = (nptr < 0 && fmt.jleft == FALSE) ? fmt.width - 1 : fmt.width;
	nsp = (((int)ft_strlen(str) + 2) < fmt.prc) ?
		fmt.width - fmt.prc : fmt.width - (ft_strlen(str) + 2);
	i = 0;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	fmt.total += ft_putstr("0x");
	while (fmt.prc-- > (int)ft_strlen(str))
		fmt.total += write(1, "0", 1);
	fmt.total += ft_putstr(&str[i]);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, ' ', fmt);
	free(str);
	return (fmt);
}

t_format			per_writer(t_format fmt)
{
	int				nsp;

	nsp = fmt.width - 1;
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(nsp, fmt.zeros, fmt);
	fmt.total += write(1, "%", 1);
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(nsp, ' ', fmt);
	return (fmt);
}

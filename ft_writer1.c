/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:40 by omercade          #+#    #+#             */
/*   Updated: 2020/09/28 19:20:42 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			char_writer(va_list vl, t_format fmt)
{
	char c;

	c  = va_arg(vl, int);
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - 1, ' ', fmt);
	fmt.total += write(1, &c, 1);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - 1, ' ', fmt);
	return (fmt);
}

t_format			str_writer(va_list vl, t_format fmt)
{
	int		i;
	char	*st;
	int		len;

	st = va_arg(vl, char *);
	len = ft_strlen(st);
	i = 0;
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - len, ' ', fmt);
	while (st[i] != 0 || i < fmt.prc)
	{
		fmt.total += write(1, &st[i], 1);
		i++;
	}
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	return (fmt);
}

t_format			ptr_writer(va_list vl, t_format fmt)
{
	void		*ptr;
	long int	nptr;
	int			i;
	int			len;
	char		*base;

	base = ft_strdup("0123456789abcdef");
	ptr = va_arg(vl, void *);
	nptr = (long)&ptr;
	len = ft_itoa_base(nptr, base, 1) + 2;
	i = 0;
	if (fmt.jleft == TRUE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	fmt.total += ft_putstr("0x");
	fmt.total += ft_itoa_base(nptr, base, 0);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	return (fmt);
}

t_format			per_writer(t_format fmt)
{
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - 1, ' ', fmt);
	fmt.total += write(1, "%", 1);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - 1, ' ', fmt);
	return (fmt);
}

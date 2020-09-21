/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:40 by omercade          #+#    #+#             */
/*   Updated: 2020/09/21 19:01:46 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			char_writer(va_list vl, t_format fmt)
{
	char c;

	c  = va_arg(char *, char);
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - 1, ' ', fmt);
	if (fmt.prc > 0)
		fmt->total += write(1, &c, 1);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - 1, ' ', fmt);
	return (fmt);
}

t_format			str_writer(va_list vl, t_format fmt)
{
	int i;
	char *st;
	int len;

	st = va_arg(char *, char *);
	len = ft_strlen(st);
	i = 0;
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - len, ' ', fmt);
	while (st[i] != 0 || i < fmt.prc)
	{
		fmt.total += write (1, &st[i], 1);
		i++;
	}
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	return (fmt);
}

t_format			ptr_writer(va_list vl, t_format fmt)
{
	void *ptr;
	long nptr;
	int i;
	int len;

	ptr = va_arg(char *, void *);
	nptr = &ptr;
	i = 0;
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - len, ' ', fmt);
	while (st[i] != 0 || i < fmt.prc)
	{
		fmt.total += write (1, &st[i], 1);
		i++;
	}
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - len, ' ', fmt);
	return (fmt);
}

t_format			per_writer(t_format fmt)
{
	if (fmt.jleft == TRUE)
		ft_writewidth(fmt.width - 1, ' ', fmt);
	if (fmt.prc > 0)
		fmt.total += write(1, "%", 1);
	if (fmt.jleft == FALSE)
		fmt = ft_writewidth(fmt.width - 1, ' ', fmt);
	return (fmt);
}

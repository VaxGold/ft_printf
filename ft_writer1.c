/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:40 by omercade          #+#    #+#             */
/*   Updated: 2020/03/05 15:58:52 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			char_writer(va_list vl, t_format fmt)
{
	char c;

	c  = va_arg(char *, char);
	fmt->total += write(1, &c, 1);
	return (fmt);
}

t_format			str_writer(va_list vl, t_format fmt)
{
	char *st;
	st = va_arg(char *, char *);
	return (fmt);
}

t_format			ptr_writer(va_list vl, t_format fmt)
{
	void *ptr;
	long nptr;

	ptr = va_arg(char *, void *);
	nptr = &ptr;
	fmt = dtoh(nptr, li);
}

t_format			per_writer(t_format fmt)
{
	li->total += write(1, "%", 1);
	return (li);
}

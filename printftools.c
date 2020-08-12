/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:19:08 by omercade          #+#    #+#             */
/*   Updated: 2020/03/06 13:42:04 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0:
	while (str[i] != 0)
	{
		c += write(1, &str[i], 1);
		i++;
	}
	return (c);
}

t_format	write_width(t_format fmt, int len)
{
	int i;

	i = 0;
	while (i++ < fmt.width - len)
	{
		if (fmt.zeros == TRUE && fmt.prc < 1 && fmt.jleft == FALSE)
			fmt.total += write(1, '0', 1);
		else
			fmt.total += write(1, ' ', 1);
	}
	return (fmt);
}

t_format	htoa(long n, t_format fmt, char *base)
{
	if (n > 15)
	{
		fmt = dtoh(n / 16, fmt, base);
		fmt->total += write(1, &base[n % 16], 1);
	}
	else
	{
		fmt->total += write(1, &base[n], 1);
	}
	return (fmt);
}
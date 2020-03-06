/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:19:08 by omercade          #+#    #+#             */
/*   Updated: 2020/03/05 17:07:01 by omercade         ###   ########.fr       */
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

t_format	htoa(long n, t_format fmt, char *base)
{
	//base = "0123456789ABCDEF";
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
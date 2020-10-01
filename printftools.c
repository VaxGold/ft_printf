/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:19:08 by omercade          #+#    #+#             */
/*   Updated: 2020/09/30 20:29:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int			ft_putstr(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != 0)
	{
		c += write(1, &str[i], 1);
		i++;
	}
	return (c);
}

t_format	ft_writewidth(int n, char cwidth, t_format fmt)
{
	int i;

	i = 0;
	while (i < n)
	{
		fmt.total += write (1, &cwidth, 1);
		i++;
	}
	return (fmt);
}

int			ft_itoa_base(int n, char *base, int mode)
{
	int nbase;
	int total;

	nbase = ft_strlen(base);
	total = 0;
	if (n < nbase && n > -nbase)
	{
		if (n < 0)
		{
			if (mode == 0)
				total += write(1, "-", 1);
			else
				total += 1;
			n = -n;
		}
		if (mode == 0)
			total += write(1, &base[n], 1);
		else
				total += 1;
	}
	else
	{
		total += ft_itoa_base((n / nbase), base, mode);
		if (mode == 0)
			total += write(1, &base[n%nbase], 1);
		else
			total += 1;
	}
	return(total);
}

int			ft_utoa(unsigned int n, char *base, int mode)
{
	int total;

	total = 0;
	if (n < 10)
	{
		if (mode == 0)
			total += write(1, &base[n], 1);
		else
				total += 1;
	}
	else
	{
		total += ft_utoa(n / 10, base, mode);
		if (mode == 0)
			total += write(1, &	base[n%10], 1);
		else
				total += 1;
	}
	return(total);
}
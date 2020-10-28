/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:19:08 by omercade          #+#    #+#             */
/*   Updated: 2020/10/27 20:13:17 by omercade         ###   ########.fr       */
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

int			ft_ndigit(long long int n, int nbase)
{
	int total;

	if (n < 0)
		total = 1;
	else
		total = 0;
	while(!(n < nbase && n > -nbase))
	{
		n /= nbase;
		total++;
	}
	return (total + 1);
}

char		*ft_itoa_base(long long int n, char *base)
{
	int		nbase;
	int		dig;
	char	*str;

	nbase = ft_strlen(base);
	dig = ft_ndigit(n, nbase);
	if ((str = malloc(dig + 1)) == 0)
		return (NULL);
	str[dig] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	dig--;
	while (!(n < nbase && n > -nbase))
	{
		str[dig] = base[n%nbase];
		n /= nbase;
		dig--;
	}
	str[dig] = base[n%nbase];
	return(str);
}
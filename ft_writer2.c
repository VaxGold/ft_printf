/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:56 by omercade          #+#    #+#             */
/*   Updated: 2020/03/06 13:54:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format			int_writer(va_list vl, t_format fmt)
{
	int i;
	int n;
	int len;

	n = va_arg(char *, char *);
	len = (ft_strlen(ft_itoa(n)) < fmt.prc) ? fmt.prc : ft_strlen(ft_itoa(n));
	i = 0;
	while (fmt.jleft == TRUE && i < fmt.prc - ft_strlen(ft_itoa(n)))
		fmt.total += write(1, '0', 1);
	if(fmt.jleft == TRUE)
		fmt.total += ft_putstr(ft_itoa(n));
	/*i = 0;
	while (i++ < fmt.width - len)
	{
		if (fmt.zeros == TRUE && fmt.prc < 1 && fmt.jleft == FALSE)
			fmt.total += write(1, '0', 1);
		else
			fmt.total += write(1, ' ', 1);
	}*/
	//fmt = write_width(fmt, len);		//Escritura del tamaño
	i = 0;
	while (fmt.jleft == FALSE && i < fmt.prc - ft_strlen(ft_itoa(n)))
		fmt.total += write(1, '0', 1);
	if(fmt.jleft == FALSE)
		fmt.total += ft_putstr(ft_itoa(n));
	return (fmt);
}

t_format			unsig_writer(va_list vl, t_format fmt)
{

}

t_format			hex_writer(va_list vl, t_format fmt)
{

}

t_format			unsighex_writer(va_list vl, t_format fmt)
{

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:28:56 by omercade          #+#    #+#             */
/*   Updated: 2020/07/21 18:13:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format            int_writer(va_list vl, t_format fmt)
{
    int     i;
    long    n;
    int     len;

    n = (long)va_arg(char *, int);
    len = (ft_strlen(ft_itoa(n)) < fmt.prc) ? fmt.prc : ft_strlen(ft_itoa(n));
    i = 0;
    while (fmt.jleft == TRUE && i++ < fmt.prc - ft_strlen(ft_itoa(n)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == TRUE)
        fmt.total += ft_putstr(ft_itoa(n));
    fmt = write_width(fmt, len);
    i = 0;
    while (fmt.jleft == FALSE && i++ < fmt.prc - ft_strlen(ft_itoa(n)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == FALSE)
        fmt.total += ft_putstr(ft_itoa(n));
    return (fmt);
}

t_format            unsig_writer(va_list vl, t_format fmt)
{
    int             i;
    unsigned int    n;
    int             len;

    n = va_arg(char *, unsigned int);
    len = (ft_strlen(ft_utoa(n, fmt)) < fmt.prc) ? fmt.prc : ft_strlen(ft_utoa(n, fmt));
    i = 0;
    while (fmt.jleft == TRUE && i++ < fmt.prc - ft_strlen(ft_utoa(n, fmt)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == TRUE)
        fmt.total += ft_putstr(ft_utoa(n, fmt));
    fmt = write_width(fmt, len);
    i = 0;
    while (fmt.jleft == FALSE && i++ < fmt.prc - ft_strlen(ft_utoa(n, fmt)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == FALSE)
        fmt.total += ft_putstr(ft_utoa(n, fmt));
    return (fmt);
}

t_format            hex_writer(va_list vl, t_format fmt)
{
    int             i;
    unsigned int    n;
    int             len;
    char[16]        base;
    
    base = "0123456789abcdef";
    n = va_arg(char *, unsigned int);
    len = (ft_strlen(ft_htoa(n, fmt, base)) < fmt.prc) ? fmt.prc : ft_strlen(ft_htoa(n, fmt, base));
    i = 0;
    while (fmt.jleft == TRUE && i++ < fmt.prc - ft_strlen(ft_htoa(n, fmt, base)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == TRUE)
        fmt.total += ft_putstr(ft_htoa(n, fmt, base));
    fmt = write_width(fmt, len);
    i = 0;
    while (fmt.jleft == FALSE && i++ < fmt.prc - ft_strlen(ft_htoa(n, fmt, base)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == FALSE)
        fmt.total += ft_putstr(ft_htoa(n, fmt, base));
    return (fmt);
}

t_format            unsighex_writer(va_list vl, t_format fmt)
{
    int             i;
    unsigned int    n;
    int             len;
    char[16]        base;

    base = "0123456789ABCDEF";
    n = va_arg(char *, unsigned int);
    len = (ft_strlen(ft_htoa(n, fmt, base)) < fmt.prc) ? fmt.prc : ft_strlen(ft_htoa(n, fmt, base));
    i = 0;
    while (fmt.jleft == TRUE && i++ < fmt.prc - ft_strlen(ft_htoa(n, fmt, base)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == TRUE)
        fmt.total += ft_putstr(ft_htoa(n, fmt, base));
    fmt = write_width(fmt, len);
    i = 0;
    while (fmt.jleft == FALSE && i++ < fmt.prc - ft_strlen(ft_htoa(n, fmt, base)))
        fmt.total += write(1, '0', 1);
    if(fmt.jleft == FALSE)
        fmt.total += ft_putstr(ft_htoa(n, fmt, base));
    return (fmt);
}
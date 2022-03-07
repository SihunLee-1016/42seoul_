/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:50 by silee             #+#    #+#             */
/*   Updated: 2022/03/07 17:56:50 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void    print_char(va_list data);
{
    write(1, va_arg(data, char));
}

void    print_string(va_list data)
{
    int data_len;
    char    *s;
    
    s = va_arg(data, char *);
    while (*s != '\0')
    {
        write(1, s, 1);
        *s++;
    }
    write(1, "", 1);
}

void    print_demical(va_list data)
{
    int     num;
    char    *str_num;
    
    num = va_arg(data, int);
    str_num = ft_itoa(num);
    while (num > 0)
    {
        num = num / 10;
        len++
    }
    write(1, str_num, len);
    free (str_num);
}

void    print_integer(va_list data)
{
    int     num;
    char    *str_num;
    
    num = va_arg(data, int);
    str_num = ft_itoa(num);
    while (num > 0)
    {
        num = num / 10;
        len++
    }
    write(1, str_num, len);
    free (str_num);
}
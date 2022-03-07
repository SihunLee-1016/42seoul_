/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxX%.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:52 by silee             #+#    #+#             */
/*   Updated: 2022/03/07 19:15:30 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_u_demical(va_list data)
{
    unsigned int num;

    num = va_arg(data, unsigned int);

}

void    print_low_hexa(va_list data)
{
    int num;

    num = va_arg(data, unsigned int);

}
void    print_up_hexa(va_list data)
{
    int num;

    num = va_arg(data, unsigned int);

}
void    print_percent(va_list data)
{
    char    c;

    c = va_arg(data, char);
    write(1, &c, 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:50 by silee             #+#    #+#             */
/*   Updated: 2022/02/14 18:14:21 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void    print_char(va_list data);
void    print_string(va_list data);
void    print_address(va_list data);
void    print_demical(va_list data);
void    print_integer(va_list data);
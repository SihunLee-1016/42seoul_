/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:45:28 by silee             #+#    #+#             */
/*   Updated: 2022/03/07 19:15:14 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    if (*str == '\0')
    {
        write (1,"",1);
        return (ERROR);
    }
    int     res;
    va_list data;

    va_start (data,str);
    res = circulate_str((char *)str, data);
    if (res == ERROR)
        return (0);
}

int circulate_str(char *str,va_list data)
{
    int ret;

    ret = 1;
    while (*str != '\0')
    {
		// %뒤에 지정되지 않은 서식지정자가 온다면 %와 바로 뒤의 문자를 제외하고 작동.
        if (*str == '%')
        {
			*str++;
           ret = check_vaild_N_print(*str, data);
            if (ret == ERROR)
                break ;
        }
		else //null은 출력이 안되는 구조.
			write(1, str,1);
		*str++;
    }
	return (ret);
}
//출력하는 함수 하나가 있어야할 거 같음. data type은 알았으니 값과 가변인자포인터를 넘겨줌.

int check_vaild_N_print(char str, va_list data)
{
    if (str == 'c')
        print_char(data);
    else if (str == 's')
        print_string(data);
    else if (str == 'p')
        print_address(data);
    else if (str == 'd')
        print_demical(data);
    else if (str == 'i')
        print_integer(data);
    else if (str == 'u')
        print_u_demical(data);
    else if (str == 'x')
        print_low_hexa(data);
    else if (str == 'X')
        print_up_hexa(data);
    else if (str == '%')
        print_percent(data);
    else
        return (ERROR);
	return (SUCCESS)
}

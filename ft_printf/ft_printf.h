/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:45:31 by silee             #+#    #+#             */
/*   Updated: 2022/02/15 17:23:43 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define SUCCESS 1
# define ERROR -1

int     ft_printf(const char *, ...);
int	    ft_strlen(const char *s)
void    print_char(va_list data);
void    print_string(va_list data);
void    print_address(va_list data);
void    print_demical(va_list data);
void    print_integer(va_list data);
void    print_u_demical(va_list data);
void    print_low_hexa(va_list data);
void    print_up_hexa(va_list data);
void    print_percent(va_list data);
int	    len_of_int(int n);
int	    plus_minus(int n);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isspace(char sstr);
int		ft_check_flow(long long num, int c, int minus);
int		ft_atoi(const char *str);

#endif

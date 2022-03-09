/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:45:31 by silee             #+#    #+#             */
/*   Updated: 2022/03/09 15:11:44 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define SUCCESS 1
# define ERROR -1
int		ft_printf(const char *str, ...);
int		circulate_str(char *str, va_list data);
int		check_vaild_N_print(char str, va_list data);
int		print_char(va_list data);
int		print_string(va_list data);
int		print_demical(va_list data);
int		print_integer(va_list data);
int		hexa_num_len(unsigned long num);
void	ft_ui_2_low_hexa(unsigned long num, int len);
void	ft_ui_2_up_hexa(unsigned long num, int len);
int		print_low_hexa(va_list data);
int		print_up_hexa(va_list data);
int		num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		print_u_demical(va_list data);
int		hexa_num_len(unsigned long num);
void	ft_ul_2_hexa(unsigned long num, int len);
int		print_address(va_list data);
int		print_percent(va_list data);
int		ft_print_str_fd(char *s, int fd);
#endif

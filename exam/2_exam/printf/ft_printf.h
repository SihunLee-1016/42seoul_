#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int     ft_strlen(char *str);
int     len_of_num(int num);
char    *ft_itoa(int num);
int     ft_putstr(char *str);
int     ft_print_d(int num);
int     check_type_n_execute(char c, va_list data);
int     ft_printf(char *str, ...);
#endif
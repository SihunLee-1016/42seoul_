#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}


int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (str == 0)
        return (0);
    while (str[i])
        i++;
    return (i);
}


int len_of_num(int num)
{
    int i;

    i = 0;
    while (num > 0)
    {
        i++;
        num = num / 10;
    }
    return (i);
}

char    *ft_itoa(int num)
{
    int i;
    int tmp;
    char    *ret;
    int     len;

    len = len_of_num(num);
    ret = malloc(sizeof(char *) * (len + 1));
    if (!ret)
        return (NULL);
    ret[len] = '\0';
    tmp = num;
    if (tmp < 0)
        tmp = -tmp;
    while (len-- > 0)
    {
        ret[len] = tmp % 10 + '0';
        tmp = tmp / 10;
    }
    if (num < 0)
        ret[0] = '-';
    return (ret);
}

int ft_print_d(int num)
{
    char c;
    int ret;
    int len;
    char *s_num;

    ret = 0;
    s_num = ft_itoa(num);
    ret = ft_putstr(s_num);
    free (s_num);
    return (ret);
}

int ft_print_x(unsigned int num)
{
    
}

int check_type_n_execute(char c, va_list data)
{
    int res;
    char    *str;

    res = 0;
    if (c == 'd')
        res = ft_print_d(va_arg(data, int));
    else if (c == 's')
    {
        str = va_arg(data, char *);
        if (str == NULL)
            res += ft_putstr("(null)");
        else
            res += ft_putstr(str);
    }
    // else if (c == 'x')
    //     ft_print_x();
    else
        return (0);
    return (res);
}

int ft_printf(char *str, ...)
{
    va_list data;
    int i;
    int res;

    i = 0;
    res = 0;
    va_start(data, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            res += check_type_n_execute(str[i], data);
        }
        else
            res += write(1, &str[i], 1);
        i++;
    }
    va_end (data);
    printf("res %d \n", res);
    return (res);
}


int main()
{
    int res1;
    int res2;
    res1 =ft_printf("Magic %s is %d\n", "number", 42);
    res2 =ft_printf("%s\n", "toto");

    printf ("%d %d ",res1, res2);
}
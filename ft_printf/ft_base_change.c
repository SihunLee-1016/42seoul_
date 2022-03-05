#include "ft_printf.h"
char ft_base_change(unsigned long num)
{
    unsigned long   mod;
    int             len;
    char            *ret;
    char            *tmp;
    while (1)
    {
        mod = num % 16;
        if (mod < 10)
            *ret = '0' + mod;
        else
            *ret = 'a' + (mod - 10);
            
        num = num / 16;
        *ret++;
        if (num == 0)
            break;
    }
    *ret = '\0';

    len = ft_strlen(ret);
    while (*ret != 0)
        *ret
}
#include "get_next_line.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    int     len;
    int     i;
    char    *ret;

    i = 0;
    len = ft_strlen(str);
    ret = malloc(sizeof(char *) * (len + 1));
    if (!ret)
        return (NULL);
    while (str[i])
    {
        ret[i] = str[i];
        i++;
    }
    return (ret);
}

char *get_next_line(int fd)
{
    char    ret[10000000];
    char    *res;
    char    buf[2];
    int     i;
    int     byte;

    i = 0;
    if (fd < 0)
        return (0);
    byte = read(fd, &buf, 1);
    buf[byte] = '\0';
    if (buf[0] == '\n' && byte == 0)
    {
        res = ft_strdup(buf);
        return (res);
    }
    while (byte > 0)
    {
        ret[i++] = buf[0];
        if (buf[0] == '\n')
            break ;
        byte = read(fd, &buf, 1);
        buf[byte] = '\0';
    }
    if (byte <= 0 && i == 0)
        return (0);
    ret[i] = '\0';
    res = ft_strdup(ret);
    return (res);
}

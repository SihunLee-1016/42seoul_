#include <unistd.h>
#include <string.h>
#include <stdio.h>

// char    *ft_strjoin(char *s1, char *s2)
// {
//     int     sum;
//     char    *ret;

//     if (s1 || s2)
//         return (0);
//     sum = strlen(s1) + strlen(s2);
//     ret = (char *)malloc(sizeof(char) * (sum + 1));
//     if (!ret)
//         return (0);
//     *ret = '\0';
//     strcat(ret, s1);
//     strcat(ret, s2);
//     return (ret);
// }


int ft_check_dup (char *s1, char c)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] == c)
            return (1);
        i++;
    }
    return (0);
}
int main (int argc, char **argv)
{
    char    *p_str;
    int     i;
    int     j;
    int     k;
    int     cnt;

    i = 1;
    if (argc != 3)
    {
        write(2, "\n", 1);
        return (0);
    }
    printf("%c", argv[1][0]);
    // p_str = malloc(sizeof(char) * 2);
    // if (!p_str)
    //     return (0);
    // p_str[0] = argv[1][0];
    // p_str[1] = '\0'; 
    while (argv[1][i])
    {
        j = 0;
        cnt = 0;
        while (j < i)
        {
            if (argv[1][i] == argv[1][j])
                cnt ++;
            j++;
        }
        if (cnt == 0)
            printf("%c", argv[1][i]);
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        j = 0;
        k = 0;
        cnt = 0;
        if (ft_check_dup(argv[1], argv[2][i]) == 1)
            cnt +=1 ;
        while (j < i)
        {
            if (argv[2][i] == argv[2][j])
                cnt ++;
            j++;
        }
        if (cnt == 0)
            printf("%c", argv[2][i]);
        i++;
    }
}
